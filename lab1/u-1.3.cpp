#include <iostream>

class A {
public:
  A() 
    {std::cout << "The default contructor" << std::endl; }
  A(const A & ref) 
    {std::cout << "The copy contructor" << std::endl; }
  ~A() 
    {std::cout << "The destructor" << std::endl; }
  A(char * s) 
    {std::cout << "Some other constructor " << s << std::endl;}
  A & operator=(const A & s) 
    {std::cout << "The assignment operator" << std::endl; 
      return *this;}
};

void no_ref(A a) {}
void with_ref(const A & a) {}

int main()
{
  std::cout << "A a(my name is a)" << std::endl;
  A a("my name is a"); // Some other constructor
  // generates a warning FOR DEPRECATED CONVERSTION FROM STRING CONST TO CHAR.
  // fix by:
  // char msg[] = "my name is a";
  // A a(msg); /have not tested it, but stackowerflow told me.
  std::cout << "A b=a" << std::endl;
  A b = a;         // vad är skillnaden: copy constructor
  std::cout << "A c(a)" << std::endl;
  A c(a);          // mellan dessa: copy constructor
  std::cout << "A d" << std::endl;
  A d;             // tre tekniker?: default constructor
  std::cout << "d = a" << std::endl;
  d = a; // assignment operator

  std::cout << "no_ref(a)"<< std::endl;
  no_ref(a);       // Bildas temporära objekt?

  // Den kör:
  // The copy constructor.
  // sen, the destructor.

  std::cout << "with_ref(a)" << std::endl;
  with_ref(a);     // Bildas temporära objekt?

  // Default constructor körs 5 times.
  std::cout << "A *aa = new A[5}]" << std::endl;
  A *aa = new A[5];

  std::cout << "delete aa;" << std::endl;
  delete aa;       // Vad kommer att hända?
  // segfaultar pa delete

  std::cout << "return 0" << std::endl;
  return 0;
}
