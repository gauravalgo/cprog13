#include <iostream>
#include <stdexcept>
#include "Vector14.h"
#include "Vector14.cpp"


int main()
{
    // Nagra saker som ska fungera:
    Vector a((int)7);           // initiering med 7 element
    Vector b(a);           // kopieringskonstruktor 
    Vector c = a;          // kopieringskonstruktor 

    a = b;                 // tilldelning genom kopiering
    a[5] = 7;              // tilldelning till element

    const Vector e(10);    // konstant objekt med 10 element
    int i = e[5];          // const int oper[](int) const kors
    i = a[0];              // vektorn ar nollindexerad
    i = a[5];              // int oper[](int) kors
    int x = 2;
    Vector v(8);
    int i2 = v[7];
    v[3] = x; // OBS, ska fungera!
    Vector v2;
    v2 = {1, 2, 5};
    a[5]++;                // oka vardet till 8
    Vector hej(7);
    hej[0] = 1;
    hej[4] = 5;
    Vector hej2(5);
    hej2=hej;
    return 0;

    try {
        i = e[10];             // forsoker hamta element som ligger utanfor e
    } catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }/*
    
#if 0
    // Diverse saker att testa
    e[5] = 3;              // fel: (kompilerar ej) tilldelning till const
    b = b;                 // hmm: se till att inte minnet som skall behallas frigors
#endif

    return 0;*/
}
