/*
 * cccc_rec.cc
 */

#include "cccc_itm.h"
#include "cccc_rec.h"
#include "cccc_db.h"

CCCC_Project* CCCC_Record::active_project=NULL;
CCCC_Project* CCCC_Record::get_active_project() { return active_project; }
void CCCC_Record::set_active_project(CCCC_Project* prj) { active_project=prj; }

void CCCC_Record::merge_flags(string& new_flags)
{
  const char *new_flag_array=new_flags.c_str();
  const char *flag_array=flags.c_str();
  unsigned int len=strlen(flag_array);
  if(strlen(new_flag_array)==len)
    {
      char buf[100];
      unsigned int i;
      for(i=0; i<len;i++)
	{
	  if(flag_array[i]=='?')
	    {
	      buf[i]=new_flag_array[i];
	    }
	  else
	    {
	      buf[i]=flag_array[i];
	    }
	}
      buf[len]='\0';
      flags=buf;
    } 
  else 
    {
      // if the parent record has just been created it may have
      // an empty flags member, so we use Resolve_Fields to copy
      // the flags from the first extent
      Resolve_Fields(flags,new_flags);
    }
}

void CCCC_Record::add_extent(CCCC_Item& is)
{
  CCCC_Extent *new_extent=new CCCC_Extent;
  new_extent->GetFromItem(is);
  CCCC_Extent *inserted_extent=extent_table.find_or_insert(new_extent);
  if(new_extent != inserted_extent)
    {
      delete new_extent;
    }
}


string CCCC_Record::name(int /* level */) const { return ""; }
string CCCC_Record::key() const { return name(nlRANK); }











