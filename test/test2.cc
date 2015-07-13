//## test2.cc
//## test source file for the structural metrics measured by CCCC.
//##
//## This file defines the following classes:
//## Test2a
//## Test2b
//## Test2c
//## It also defines the following method
//## Test2e::Test2e(const Test2a&)

//## The following relationships should be visible in the code:
//## Test2a uses Test2e by inheritance with public visibility
//## Test2a uses Test2b by containment by reference with public visibility
//## Test2a uses Test2b by parameter passing by value with private visibility
//## Test2c uses uses Test2d by containment by value with protected visibility
//## Test2e uses Test2a by parameter passing by value with unknown visibility

class Test2a : public Test2e
{
public:
  Test2b *m_2b;
private:
  void doSomething(Test2b);
};

class Test2c 
{
protected:
  Test2d m_2d;
};

//## The extent record for the following class definition would normally be 
//## brought into the database alongside the extent record for the declaration
//## of the method within the class definition, allowing the visibility to be
//## known.  In this case, we are choosing to analyze this definition without
//## that knowledge, hence the visibility of the method cannot be inferred and
//## the analyzer should assume that it is of the less desirable visible 
//## classification. 
Test2e::Test2e(const Test2a&)
{
}

//## The code above should give rise to the following relationships
//## The annotations [], [C], [V], [CV] show how the relationship is
//## classified on the two scales concrete/abstract and visible/hidden
//## where abstract relationships are ones where the supplier is treated
//## as an opaque type for the purposes of the interface (i.e. containment
//## or parameter passing by reference), and hidden ones are where the
//## supplier is known not to appear in the protected or public interface of 
//## the client.
//## Class               Clients                     Suppliers
//## Test2a              Test2d[V]                   Test2e[V],Test2b[CV]
//## Test2b              Test2a[CV]
//## Test2c                                          Test2d[CV]  
//## Test2d              Test2d[CV]                  Test2a[V]
//## Test2e              Test2a[CV]



