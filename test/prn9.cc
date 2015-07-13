// PRN9.cc
// SourceForge bug tracker item 233548
// Submitted by Victor B Putz
// Tests handling of inheritance relationships specified as 'public virtual'
// and 'virtual public' as both are accepted by GCC.

class A
{ 
}; 

class B : public virtual A
{ 
}; 

class C : virtual public A
{
};




