// cccc_met.cc

#include "cccc.h"
#include "cccc_itm.h"
#include "cccc_met.h"
#include <strstream>
using std::ostrstream;

#include "cccc_opt.h"

Metric_Treatment::Metric_Treatment(CCCC_Item& treatment_line)
{
  lower_threshold=0;
  upper_threshold=0;
  numerator_threshold=0;
  width=0;
  precision=0;

  string option_dummy, treatment_dummy, lothresh_str, 
    hithresh_str, numthresh_str, width_str, precision_str;

  if(
     // treatment_line.Extract(option_dummy) &&
     // treatment_line.Extract(treatment_dummy) &&
     treatment_line.Extract(code) &&
     treatment_line.Extract(lothresh_str) &&
     treatment_line.Extract(hithresh_str) &&
     treatment_line.Extract(numerator_threshold) &&
     treatment_line.Extract(width) &&
     treatment_line.Extract(precision) &&
     treatment_line.Extract(name)
     )
    {
      lower_threshold=atof(lothresh_str.c_str());
      upper_threshold=atof(hithresh_str.c_str());
    }
}

CCCC_Metric::CCCC_Metric() 
{ 
  set_ratio(0,0); 
  set_treatment(""); 
}

CCCC_Metric::CCCC_Metric(int n, const char* treatment_tag) 
{ 
  set_ratio(n,1); set_treatment(treatment_tag); 
}

CCCC_Metric::CCCC_Metric(int n, int d, const char* treatment_tag) 
{ 
  set_ratio(n,d); set_treatment(treatment_tag); 
}

void CCCC_Metric::set_treatment(const char* code) 
{
  treatment=CCCC_Options::getMetricTreatment(code);
}

void CCCC_Metric::set_ratio(float _num, float _denom) 
{ 
  numerator=_num; denominator=_denom;
}
   
EmphasisLevel CCCC_Metric::emphasis_level() const 
{ 
  EmphasisLevel retval=elLOW;
  if(treatment!=NULL && numerator>treatment->numerator_threshold)
    {
      if( numerator > (treatment->upper_threshold*denominator) )
	{
	  retval=elHIGH;
	} 
      else if(numerator> (treatment->lower_threshold*denominator) )
	{
	  retval=elMEDIUM;
	}
    }
  return retval;
}

string CCCC_Metric::code() const 
{ 
  string retval;
  if(treatment != NULL) { retval=treatment->code; }
  return retval; 
}

string CCCC_Metric::name() const 
{ 
  string retval;
  if(treatment != NULL) { retval=treatment->name; }
  return retval; 
}
    
string CCCC_Metric::value_string() const
{
  string retval;
  char numerator_too_low='-';
  char infinity='*';
  
  ostrstream valuestr;
  valuestr.setf(std::ios::fixed);
  int width=6, precision=0;
  float n_threshold=0, low_threshold=1e9, high_threshold=1e9;
  if(treatment!=NULL)
    {
      width=treatment->width;
      precision=treatment->precision;
      n_threshold=treatment->numerator_threshold;
      low_threshold=treatment->lower_threshold;
      high_threshold=treatment->upper_threshold;
    }
  valuestr.width(width);
  valuestr.precision(precision);
  if(numerator<n_threshold)
    {
      string too_low_string(width,numerator_too_low);
      valuestr << too_low_string;
    }
  else if(denominator==0)
    {
      string infinity_string(width,infinity);
      valuestr << infinity_string;
    }
  else
    {
      float result=numerator;
      result/=denominator;
      valuestr << result;
    }
  valuestr << std::ends;
  retval=valuestr.str();
  return retval;
}

char *internal_treatments[] =
{
  "LOCf@30@100@0@6@0@Lines of code/function@",
  "LOCm@500@2000@0@6@0@Lines of code/module @",
  "LOCp@999999@999999@0@6@0@Lines of code/project @",
  "MVGf@10@30@0@6@0@Cyclomatic complexity/function@",
  "MVGm@200@1000@0@6@0@Cyclomatic complexity/module@",
  "MVGp@999999@999999@0@6@0@Cyclomatic complexity/project@",
  "COM@999999@999999@0@6@0@Comment lines@",
  "M_C@5@10@5@6@3@MVG/COM McCabe/comment line@",
  "L_C@7@30@20@6@3@LOC/COM Lines of code/comment line@",
  "FI@12@20@0@6@0@Fan in (overall)@",
  "FIv@6@12@0@6@0@Fan in (visible uses only)@",
  "FIc@6@12@0@6@0@Fan in (concrete uses only)@",
  "FO@12@20@0@6@0@Fan out (overall)@",
  "FOv@6@12@0@6@0@Fan out (visible uses only)@",
  "FOc@6@12@0@6@0@Fan out (concrete uses only)@",
  "IF4@100@1000@0@6@0@Henry-Kafura/Shepperd measure (overall)@",
  "IF4v@30@100@0@6@0@Henry-Kafura/Shepperd measure (visible only)@",
  "IF4c@30@100@0@6@0@Henry-Kafura/Shepperd measure (concrete only)@",
  "WMC1@30@100@0@6@0@Weighting function = 1 unit per method@",
  "WMCv@10@30@0@6@0@Weighting function = 1 unit per visible method@",
  "DIT@3@60@6@0@Depth of Inheritance Tree@",
  "NOC@4@15@0@6@0@Number of children@",
  "CBO@12@30@0@6@0@Coupling between objects@",
  NULL
};








