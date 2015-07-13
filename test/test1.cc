//## test1.cc 
//## test case illustrating simple procedural metrics
//## Lines starting //## are ignored by CCCC so they will be used in this
//## file for explanatory comments (as opposed to comments which we wish
//## to count).
//## The file is annotated along the way with comment lines like these
//## scope/comment                                          LOC   COM   MVG
//## definition of class Test1 (start)                        0     0     0
//## running totals                                           0     0     0
//## definition of class Test1 (end)                          0     0     0
//## Note that extents nest, so there is effectively a stack of 
//## running totals for each extent open at a particular point in a file

//## definition of class Test1 (start)                        0     0     0
// Leading comment for class.
class Test1
{
//## running totals                                           2     1     0
  // Internal comment for class. 
  // This should not be associated with the following function due to 
  // the intervening visibility declaration.
//## running totals                                           2     4     0
public:
//## running totals for definition of class Test1 (push)      3     4     0
//## definition of method Test1::method1 (start)              0     0     0
  // Leading comment for inline method
  void method1()
    {
//## running totals                                           2     1     0
      int s=1;
      switch(s)
//## running totals                                           4     1     1
	{
	case 1:
	  break;
//## running totals                                           7     1     2
	case 2:
	  break;
//## running totals                                           9     1     3
	default:
	  break;
//## running totals                                          11     1     4
	}
    }
//## definition of method Test1::method1 (end)               13     1     4
//## running totals for definition of class Test1 (pop+push)  3     4     0
//## declaration of method Test1::method2 (start)             0     0     0
  void method2();
//## declaration of method Test1::method2 (end)               1     0     0
//## running totals for definition of class Test1 (pop)       3     4     0
};
//## definition of class Test1 (end)                          4     4     0

//## definition of method Test1::method2 (start)              0     0     0
void Test1::method2()
{
  if(1)
    {
      // do nothing
    }
 }
//## definition of method Test1::method2 (end)                6     1     1

//## after processing the whole file we expect to find the following
//## extents recognized and mentioned in the .db file
//## definition of class Test1                               LOC:4 COM:4 MVG:0
//## definition of method Test1::method1                     LOC:13 COM:1 MVG:4
//## declaration of method Test1::method2                    LOC:1 COM:0 MVG:0
//## definition of method Test1::method2                     LOC:6 COM:1 MVG:1
