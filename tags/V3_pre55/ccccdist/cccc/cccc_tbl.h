/*
 * cccc_tbl.h
 * 
 * defines the database used by CCCC to generate a report
 */
#ifndef CCCC_TBL_H
#define CCCC_TBL_H

#include <iostream>
#include <string>

#include <map>

using std::string;

// CCCC_Table started its life as an array of pointers to CCCC_Records.
// It will ultimately become identical to a std::map from string to T*.
// In the mean time we are supporting a legacy API.
template <class T> class CCCC_Table 
: public std::map<string,T*>
{
  typedef std::map<string,T*> map_t;
  map_t::iterator iter_;
  bool sorted;

 public:
  CCCC_Table();
  virtual ~CCCC_Table();
  int records();
  T* find(string name);
  T* find_or_insert(T* new_item_ptr);
  bool remove(T* old_item_ptr);
  void reset_iterator();
  T* first_item();
  T* next_item();
  virtual int get_count(const char *count_tag);
  void sort();
};

#endif // CCCC_DB_H

