// prn11.cc
// SourceForge bug tracker item 233585
// Submitted by Victor B Putz
// Tests parsing of namespace declarations
// I am not confident that the present counting rules applying
// to this construct are optimal yet.

namespace A 
{ 
  void b( void ); 
}; 

void A::b( void ) 
{ 
} 


