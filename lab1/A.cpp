#include <iostream>
using namespace std;
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

//kopia
void no_ref(A a) {}
//referens, kan modda a, kan inte �ndra p� referens
void with_ref(const A & a) {}

int main()
{
    A a("my name is a");
    A b = a;         // calls on copy, make a copy b of a
    A c(a);          // copy without assigning the copy to a variable
    A d;             // constructs a new A object.
    d = a;           // assignment op, ?
    cout << "before no_ref\n";
    no_ref(a);       // k�r copy, s� tempor�ra objekt bildas, k�r sedan destruktor s� objektet tas bort
    with_ref(a);     // Skickar in en referens, s� inga kopior bildas
    cout << "after no_ref\n";
    A *aa = new A[5]; // 5ggr default
    cout << "before delete\n";
    delete[] aa;       // Vad kommer att h�nda? Destruct, segmentation fault
    //delete �r mer keyword, anropar tillh�rande destruktor
    cout << "after delete\n";
    return 0;
}
