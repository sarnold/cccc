// prn10.cc
// SourceForge bugtracker item 233584
// submitted by Victor B Putz
// Tests handling of data members and globals specified as 
// 'const static' and 'static const' as both are accepted by GCC.

const static char csNonMember;
static const char scNonMember;

class A 
{ 
    const static char csMember; 
    static const char scMember; 
}; 



