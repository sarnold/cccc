// cccc_opt.h
#ifndef _CCCC_OPT_H
#define _CCCC_OPT_H

// This file defines the object which holds the major configuration
// options for the CCCC program including:
//  - the default language associated with each file name extension; 
//  - the treatment of specific values of each metric; and
//  - the application of dialect specific parsing rule (e.g. rule to 
//    ignore MSVC++-specific pseudo-keywords when parsing the 
//    MS C++ dialect.

// This is a natural singleton class, hence all member functions are static
// and all data will be declared with static file scope in the implementation
// file.

#include "cccc.h"
#include "cccc_itm.h"

class Metric_Treatment;

class CCCC_Options
{
 public:
  // initialise using a file
  static void Load_Options(const string& filename);

  // initialise using hard-coded defaults
  static void Load_Options();

  // save the current set of options to a file
  static void Save_Options(const string& filename);

  // add a new option into the current option set
  static void Add_Option(CCCC_Item& option_line);

  // map a filename to a language
  static string getFileLanguage(const string& filename);
  
  // map a metric name to a Metric_Treatment object
  static Metric_Treatment *getMetricTreatment(const string& metric_tag);

  // the following function allows the parser to use special 
  // handling rules for identifiers in particular situations
  // (especially pseudo-keywords like BEGIN_MESSAGE_MAP)
  static string dialectKeywordPolicy(const string& lang, const string& kw);
};

#endif

  





