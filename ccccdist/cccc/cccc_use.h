/*
 * cccc_use.h
 */
#ifndef CCCC_USE_H
#define CCCC_USE_H

#include "cccc_rec.h"

class CCCC_Module;

static const string USEREL_PREFIX="CCCC_UseRel";
static const string USEEXT_PREFIX="CCCC_UseExt";

enum UserelNameLevel { nlSUPPLIER=-1, nlCLIENT=-2, nlMEMBER=-3 };

class CCCC_UseRelationship : public CCCC_Record 
{
  friend class CCCC_Project;
  string supplier, client, member;
  UseType ut;
  AugmentedBool visible, concrete;
  CCCC_UseRelationship() { ut=utDONTKNOW; }

 public:
  string name( int index ) const;
  CCCC_UseRelationship(CCCC_Item& is);
  int FromFile(ifstream& infile);
  int ToFile(ofstream& outfile);
  void add_extent(CCCC_Item&);
  int get_count(const char *count_tag);
  UseType get_usetype() const { return ut; }
  AugmentedBool is_visible () const { return visible; }
  AugmentedBool is_concrete () const { return concrete; }
  void generate_report(ostream& os);
  CCCC_Module* supplier_module_ptr(CCCC_Project *prj);
  CCCC_Module* client_module_ptr(CCCC_Project *prj);
};


#endif // CCCC_USE_H






