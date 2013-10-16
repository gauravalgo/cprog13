#include "gregorian.h"
#include <stdexcept>

using namespace lab2;

const int month_length[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

Gregorian::Gregorian()
  : Date(12, 7)
{
  // get kattis time.
  time_t mytime;
  k_time(&mytime);

  struct tm *t = gmtime(&mytime);
  int year  = t->tm_year + 1900;
  int month = t->tm_mon + 1;      // m mytimenaderna och dagarna
  int day   = t->tm_mday;         // indexerade fr =n ETTt k_time(NULL);

  init(year, month, day);
}

Gregorian::Gregorian(int y, int m, int d)
  : Date(12, 7)
{
  init(y, m, d);
}

void Gregorian::init(int y, int m, int d) {
  if (!isValid(y, m , d)) {
    throw std::out_of_range("Invalid date. Check the range for days and month.");
  }
  lyear = y;
  lmonth = m;
  lday = d;
  
  JDN = convert_to_jdn();

}

long Gregorian::convert_to_jdn() const {
  long jdn;
  int Y = lyear;
  int M = lmonth;
  int D = lday;
  
  jdn = (1461 * (Y + 4800 + (M - 14)/12))/4 +(367 * (M - 2 - 12 * ((M - 14)/12)))/12 - (3 * ((Y + 4900 + (M - 14)/12)/100))/4 + D - 32075; // julian day number algorithm

  return jdn;
}


int Gregorian::days_this_month() const {
  if (lmonth == 2 && leap_year(lyear)) {
    return 29;
  }
  
  return month_length[lmonth];
}

bool Gregorian::isValid(int y, int m, int d) {
  if (d < 1 || m < 1) {
    return false;
  }

  return true;
}

bool Gregorian::leap_year(int year) const {
  if (year%400 == 0) {
    return true;
  } else if ( year%100 == 0 ) {
    return false;
  } else if (year%4 == 0) {
    return true;
  }
  return false;
}

bool Gregorian::leap_year() const {
  return leap_year(lyear);
}
