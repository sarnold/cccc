/*
 From: 
       Ruppert <ru@swb.siemens.de>
 Reply-To: 
       Ruppert <ru@swb.siemens.de>
 To: 
       tim_littlefair@hotmail.com Save Address
 CC: 
       ru@swb.siemens.de Save Address
 Subject: 
       cccc-3.pre39: Parser errors
 Date: 
       Tue, 23 May 2000 09:23:16 +0200 (MET DST)
Hi,

I have just played around a bit with cccc-3.pre39 and tried
to analyze a large body of C++ code with it. It worked quite
well, and the results look quite useful.

The parser emits, however, a number of syntax errors, which I could
track to a few specific code constructs. These constructs are
legal C/C++, but the cccc parser generates "syntax error" messages.

I have stripped down the problems to the constructs in question;
I enclose a small test program which exhibits all of them. I hope
this is useful for fixing this.


Best Regards
Dr. D.Ruppert
RTS GmbH
Schwieberdingen/Germany
ru@swb.siemens.de

*/


/*
  Problem with inline attribute in class header:

  Processing test.cc as C/C++ (c++.ansi)
  test.cc(9) syntax error at token inline
  Parser context:
  test.cc(9): trying to match class_block_item_list at 'inline
  */

class InlFunc
{
  public:
    InlFunc();
    ~InlFunc();
    inline getFunc();
};



/*
  Problem with Initialization by function invoc. at file scope:

  Processing test.cc as C/C++ (c++.ansi)
  test.cc(2) syntax error at token (
  Parser context:
  test.cc(2): trying to match instance_declaration at 'const
  */

static const double d = sqrt(1.0 / 0.003);

/*
  Problem with function pointer as class member:
  test.cc(6) syntax error at token int
  Parser context:
  test.cc(6): trying to match class_block_item_list at 'int
  */


int getInt();
class FP
{
  public:
    int (*getInt)();
};



/*
  Problem with anonymous struct type:
  test.cc(5) syntax error at token struct
  Parser context:
  test.cc(5): trying to match class_block_item_list at 'struct
  */


struct A
{
    int a;
    struct
    {
        double d;
        float e;
    } myS;
};




/*
  Problem with / in initializer for int:
  Processing test.cc as C/C++ (c++.ansi)
  test.cc(1) syntax error at token /
  Parser context:
  test.cc(1): trying to match instance_declaration at 'const
  */


const int myInt = 10 / 4;

/*
  Problem with literal 0. in float-Initializer:

   invalid token near line 2 (text was '0.')
   test.cc(2) syntax error at token ;
   */
float f = 0. ;

/*
  Problem with anonymous union:

  Processing test.cc as C/C++ (c++.ansi)
  test.cc(6) syntax error at token union
  Parser context:
  test.cc(6): trying to match class_block_item_list at 'union
  */

class Hugo_2
{
  public:
    Hugo_2();
    ~Hugo_2();
    union
    {
        int a;
        double b;
    };
};

/*
  Problem with anonymous enum:

  Processing test.cc as C/C++ (c++.ansi)
  test.cc(7) syntax error at token enum
  Parser context:
  test.cc(7): trying to match class_block_item_list at 'enum
  ...
  */

class Hugo
{
  public:
    Hugo();
    ~Hugo();
    enum
    {
        START,
        STOP
    };
};

