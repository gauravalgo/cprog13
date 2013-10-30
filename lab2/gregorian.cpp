#include "gregorian.h"

using namespace lab2;

Gregorian::Gregorian() : Julian() {
}

Gregorian::Gregorian(const Date & d) : Julian(d) {
}

Gregorian::Gregorian(int y, int m, int d) : Julian(y, m, d){
}

bool Gregorian::leap_year() const {
  return leap_year(year());
}

bool Gregorian::leap_year(int year) const {
  if (year % 400 == 0) return true; 
  if (year % 100 == 0) return false; 
  if (year % 4 == 0) return true; 
  return false;
}
