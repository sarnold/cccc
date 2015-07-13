// prn5.cc
// Prior to version 3.pre45, use of builtin types like char, int
// in parameter lists led to spurious relationships being registered
// to non-existent types 'char ', 'int '.

void MyClass::someFunction(char c)
{
  // do nothing
}
