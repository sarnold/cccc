/*
 * A L F _ PRINT. C X X
 *
 * This file contains print routines for ALF.
 *
 * Copyright (c) 1998, Sente Inc.
 *
 * $Id$
 */

#include<string.h>
#include "utils.h"
#include "AlfObject.hxx"

void alfPrintSpaces(int numTabs, FILE* fp)
{
int numBlanks;
for (numBlanks = 0; numBlanks < 4*numTabs; numBlanks++)
   fprintf(fp,"%c",' ');
}

