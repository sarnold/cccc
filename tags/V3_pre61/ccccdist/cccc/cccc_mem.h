/*
 * cccc_mem.h
 */
#ifndef CCCC_MEM_H
#define CCCC_MEM_H

#include "cccc_rec.h"

static const string MEMBER_PREFIX="CCCC_Member";
static const string MEMEXT_PREFIX="CCCC_MemExt";

enum MemberNameLevel { nlMEMBER_NAME=-1, nlMEMBER_TYPE=-2, nlMEMBER_PARAMS=-3 };

class CCCC_Member : public CCCC_Record 
{
  friend class CCCC_Project;
  friend class CCCC_Module;
  string member_type, member_name, param_list;
  Visibility visibility;
  CCCC_Module *parent;
  CCCC_Member(); 
 public:
  string name( int index ) const;
  CCCC_Member(CCCC_Item& member_data_line, CCCC_Module* parent_ptr=NULL);
  int FromFile(ifstream& infile);
  int ToFile(ofstream& outfile);
  void generate_report(ostream&); 
  int get_count(const char *count_tag);
  Visibility get_visibility();
};

#endif // CCCC_MEM_H






