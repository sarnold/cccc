#ifndef tokens_h
#define tokens_h
/* tokens.h -- List of labelled tokens and stuff
 *
 * Generated from: sor.g
 *
 * Terence Parr, Will Cohen, and Hank Dietz: 1989-1999
 * Purdue University Electrical Engineering
 * ANTLR Version 1.33MR20
 */
#define zzEOF_TOKEN 1
#define Eof 1
#define RExpr 2
#define Action 27
#define PassAction 28
#define Header 65
#define Tokdef 66
#define BLOCK 67
#define ALT 68
#define LABEL 69
#define OPT 70
#define POS_CLOSURE 71
#define CLOSURE 72
#define WILD 73
#define PRED_OP 74
#define BT 75
#define RULE 76
#define REFVAR 77
#define NonTerm 82
#define Token 83
#define ID 108
#define INT 109

#ifdef __USE_PROTOS
void sordesc(AST**_root);
#else
extern void sordesc();
#endif

#ifdef __USE_PROTOS
void header(AST**_root);
#else
extern void header();
#endif

#ifdef __USE_PROTOS
void tokdef(AST**_root);
#else
extern void tokdef();
#endif

#ifdef __USE_PROTOS
void class_def(AST**_root);
#else
extern void class_def();
#endif

#ifdef __USE_PROTOS
void rule(AST**_root);
#else
extern void rule();
#endif

#ifdef __USE_PROTOS
void block(AST**_root, int no_copy );
#else
extern void block();
#endif

#ifdef __USE_PROTOS
void alt(AST**_root, int no_copy );
#else
extern void alt();
#endif

#ifdef __USE_PROTOS
void element(AST**_root, int no_copy );
#else
extern void element();
#endif

#ifdef __USE_PROTOS
void labeled_element(AST**_root, int no_copy );
#else
extern void labeled_element();
#endif

#ifdef __USE_PROTOS
void token(AST**_root, int no_copy );
#else
extern void token();
#endif

#ifdef __USE_PROTOS
void tree(AST**_root, int no_copy );
#else
extern void tree();
#endif

#ifdef __USE_PROTOS
void enum_file(AST**_root);
#else
extern void enum_file();
#endif

#ifdef __USE_PROTOS
void defines(AST**_root);
#else
extern void defines();
#endif

#ifdef __USE_PROTOS
void enum_def(AST**_root);
#else
extern void enum_def();
#endif

#endif
extern SetWordType zzerr1[];
extern SetWordType setwd1[];
extern SetWordType zzerr2[];
extern SetWordType zzerr3[];
extern SetWordType zzerr4[];
extern SetWordType setwd2[];
extern SetWordType zzerr5[];
extern SetWordType zzerr6[];
extern SetWordType zzerr7[];
extern SetWordType zzerr8[];
extern SetWordType zzerr9[];
extern SetWordType setwd3[];
extern SetWordType zzerr10[];
extern SetWordType zzerr11[];
extern SetWordType zzerr12[];
extern SetWordType zzerr13[];
extern SetWordType zzerr14[];
extern SetWordType setwd4[];
extern SetWordType zzerr15[];
extern SetWordType zzerr16[];
extern SetWordType setwd5[];
