/*
 * cccc_ast.h
 * definition of the abstract syntax tree interface for the cccc project
 */

#ifndef __CCCC_AST_H
#define __CCCC_AST_H

#include <string>
using std::string;

#include "cccc.h"
#include "ASTBase.h"
#include "ATokPtr.h"
#include "cccc_tok.h"
#include "AParser.h"
#include "cccc_utl.h"

class AST : public ASTBase {
  friend ostream& operator << (ostream&, AST&);
 public:
  ANTLRToken token;

  // elements to control output
  int bPrintNode, bCanonicalElement;

  // canonical name of the element
  string canonical_name();  /* function to recursively generate the name */
  static char *szCurrentRuleName;
  char *szRuleName;
  // first and last token
  ANTLRToken *first_token();
  ANTLRToken *last_token();
      
  // start and end line of the source code covered by the AST
  int nStartLine();
  int nEndLine();
  
  char *filename, *classname, *membername;

  AST();
  
  AST(ANTLRTokenPtr t);
  AST(AST& ast);
  virtual ~AST();
  virtual AST& operator =(AST&);
  void free_subtrees();
    
  void preorder(ostream &os=cerr);
  void preorder_action();
  void preorder_before_action();
  void preorder_after_action();
 
#if 0
  /* supress the normal error reporting */
  void syn(_ANTLRTokenPtr t,
	   ANTLRChar* c,
	   SetWordType* swt,
	   ANTLRTokenType att,
	   int i
	   ) {}
#endif
};

ostream& operator << (ostream&, AST&);


#endif



















