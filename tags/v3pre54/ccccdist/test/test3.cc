//## test3.cc
//## This file is intended to test the performance of CCCC in measurement
//## of the metrics described in the papers by Chidamber and Kemerer
//## about 'a metrics suite for object oriented design'.

//## Test3a attempts to check the values for WMC1 and WMCv
//## When I was originally writing this class I found some bugs in the 
//## handling of operator functions, hence the fact that they are
//## extensively used in this item.
class Test3a
{
public:
  Test3a();
  ~Test3a();
  operator new();
  operator delete[]();
protected:
  operator!=();
  operator unsigned long int();
private:
  operator==();
  operator ()();
  operator []();
  operator*();
  operator.*();
  do_something();
  do_something_else();
};
//## Manual count of the above definition yields WMC1=13, WMCv=6 (including 
//## protected functions which we treat as visible).

//## Test3b1 to Test3b5 attempt to test the logic for DIT, NOC and CBO.
class Test3b1 : public Test3b0 {};
class Test3b2 : public Test3b1 {};
class Test3b4 : public Test3b3, public Test3b0, public Test3b2 {};
class Test3b5
{
public:
  Test3b5(Test3b3);
private:
  Test3b0 m_3b0;
};

//## Should get the following values:
//## class             DIT             NOC             CBO
//## Test3b0             0             2               3        
//## Test3b1             1             1               2
//## Test3b2             2             1               2
//## Test3b3             0             1               2
//## Test3b4             3             0               3          
//## Test3b5             0             0               2




