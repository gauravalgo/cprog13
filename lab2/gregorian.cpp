#include "gregorian.h"

using namespace lab2;

Gregorian::Gregorian()
  : Date(12, 7, 2013, 11, 2)
{}

Gregorian::Gregorian(int y, int m, int d)
  : Date(12, 7, y, m , d)
{}
