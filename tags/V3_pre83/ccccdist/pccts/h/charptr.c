/*
 * SOFTWARE RIGHTS
 *
 * We reserve no LEGAL rights to the Purdue Compiler Construction Tool
 * Set (PCCTS) -- PCCTS is in the public domain.  An individual or
 * company may do whatever they wish with source code distributed with
 * PCCTS or the code generated by PCCTS, including the incorporation of
 * PCCTS, or its output, into commerical software.
 *
 * We encourage users to develop software with PCCTS.  However, we do ask
 * that credit is given to us for developing PCCTS.  By "credit",
 * we mean that if you incorporate our source code into one of your
 * programs (commercial product, research project, or otherwise) that you
 * acknowledge this fact somewhere in the documentation, research report,
 * etc...  If you like PCCTS and have developed a nice tool with the
 * output, please mention that you developed it using PCCTS.  In
 * addition, we ask that this header remain intact in our source code.
 * As long as these guidelines are kept, we expect to continue enhancing
 * this system and expect to make other tools available as they are
 * completed.
 *
 * ANTLR 1.33
 * Terence Parr
 * Parr Research Corporation
 * with Purdue University and AHPCRC, University of Minnesota
 * 1989-1998
 */

#include "pcctscfg.h"

#ifdef __STDC__
#include "pccts_stdlib.h"
#else
#include <malloc.h>
#endif
#include "pccts_string.h"

/* 133MR1 include stdio.h for fprintf in charptr.c */

#include "pccts_stdio.h"

/* 133MR1 include charptr.h for Attrib in charptr.c */

#include "charptr.h"

#ifdef __USE_PROTOS
zzcr_attr(Attrib *a,int token,char *text)
#else
zzcr_attr(a,token,text)
Attrib *a;
int token;
char *text;
#endif
{
	*a = (char *) malloc(strlen(text)+1);			/* MR6 */
	if ( *a == NULL ) {fprintf(stderr, "zzcr_attr: out of memory!\n"); exit(-1);}
	strcpy(*a, text);
}
