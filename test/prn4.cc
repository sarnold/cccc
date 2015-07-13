// prn4.cc

// Classes with namespace qualifiers should have their name
// reduced to the final component.  In versions prior to 3.pre45 
// this did not happen.  On Unix systems the result was reports 
// with names like std::string.html.  On Win32, the colon is not 
// legal in file names and the report generation process terminates early.

void MyClass::someFunction(const std::string& s)
{
  // do nothing
}

