/*
 * cccc_tok.h
 * definition of the token class interface for the cccc project
 *
 */

#ifndef __CCCC_TOK_H
#define __CCCC_TOK_H

#include "cccc.h"

// before we go into the token header file, the compiler must have seen 
// a definition for enum ANTLRTokenType
// there are three conflicting 'real' definitions, one in use by each parser
// if we have seen one of these, we do not need to worry, otherwise we
// must create a dummy one
// the three definitions are in the files Ctokens.h Jtokens.h and Atokens.h
#if !defined(Ctokens_h) && !defined(Jtokens_h) && !defined(Atokens_h)
enum ANTLRTokenType { DUMMY,DEFINITION };
#endif

#include "AToken.h"
#include "cccc.h"


/*
** the class definition for ANTLRToken
** Note that the name ANTLRToken is required to be either a class or a typedef
** by the PCCTS support code
*/
class ANTLRToken : public ANTLRCommonToken {

  // Lexical counting is done by attaching running counts of each of the
  // interesting features to every token produced by the lexer
  // the parser calculates the counts for a particular region by taking
  // taking the differences of the counts for the first and last tokens
  // in the region's extent.

  // nesting levels are used to control resynchronisation
  static int RunningNesting;

  static int numAllocated;
  int CurrentNesting;
  friend ostream& operator << (ostream&,ANTLRToken&);
  friend class DLGLexer;
 public:
  static int bCodeLine;

  ANTLRToken(ANTLRTokenType t, ANTLRChar *s);
  ANTLRToken(ANTLRToken& copyTok);
  ANTLRToken();
  ANTLRToken& operator=(ANTLRToken& copyTok);
  
  virtual ~ANTLRToken();

  virtual ANTLRAbstractToken *makeToken(ANTLRTokenType tt, 
					ANTLRChar *txt, 
					int line);

  friend void IncrementNesting() { RunningNesting++; }
  friend void DecrementNesting() { RunningNesting--; }

  int getNestingLevel() { return CurrentNesting; }
  void CountToken();
  char *getTokenTypeName();
};

#define MY_TOK(t) ((ANTLRToken*)(t))
ostream& operator << (ostream&, ANTLRToken&);

extern ANTLRToken currentLexerToken;


#endif

 
