/*
 * cccc_ext.h
 */
#ifndef CCCC_EXT_H
#define CCCC_EXT_H

#include <string>
using std::string;

#include "cccc_utl.h"

class CCCC_Item;

enum ExtentNameLevel { nlFILENAME=-1, nlLINENUMBER=-2, nlDESCRIPTION=-3};
class CCCC_Extent
{
  friend class CCCC_Record;
  friend class CCCC_Project;
  
  string filename;
  string linenumber;
  string description;
  string flags;
  string count_buffer;
  UseType ut;
  Visibility v;
  static unsigned int nextkey;
  unsigned int extkey;
 public:
  CCCC_Extent();
  CCCC_Extent(CCCC_Item& is);

  string name( int index ) const;
  string key() const; 
  int GetFromItem(CCCC_Item& item);
  int AddToItem(CCCC_Item& item);
  Visibility get_visibility() const { return v; }
  int get_count(const char *count_tag);
  UseType get_usetype() const { return ut; }
  const char* get_description() const { return description.c_str(); }
};

#endif // CCCC_EXT_H






