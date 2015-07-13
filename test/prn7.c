// prn7.c
// Test case submitted by Larry Peters of ATI
// ********************************************************************
// *
// * cccc Sample code
// *
// ********************************************************************
#include <stdio.h>

///////////////////////////////////////////////////////////////////////
// First issue has to do with struct typedefs using the ugly MS style
// of declaring pointer typedefs for the struct following the struct
// definition:

typedef struct MY_STRUCT
{
    int             _iVal;
    long            _lVal;
    char           *_pszVal;
} MYSTRUCT,*PMYSTRUCT,*LPMYSTRUCT;   // These last two cause errors!

///////////////////////////////////////////////////////////////////////
// The second issue has to do with multiple line string literals.
// There are two problems here:  the first is handling multiple line
// literals -- should just be a grammar change (see below).  The second
// problem I think may require a pre-processor (yuck).  Take a look and
// let me know what you think:
char      szSimpleOne[] = "Test 1" "This is OK too"
                          "so is this!";      // Ugly but legal...

/*
// This one is too hard for the time being.
// I can't see a way to fix it without going against the
// design rule that CCCC does not run (or fake) the preprocessor
#define   MY_STR        "BLAH!"

char      szDifficultOne[] = "Test 1" MY_STR
                             "yuck!";         // Again, ugly but legal...

*/

///////////////////////////////////////////////////////////////////////
// This last one involves using the sizeof operator in the "global"
// scope.

// This one fails
long      lVal = sizeof( long );

void main()
{
    // This one works!
    long      lVal2 = sizeof( long );
}

