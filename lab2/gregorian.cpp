#include "gregorian.h"
#include <stdexcept>

using namespace lab2;

const int month_length[13] = {-1,31,28,31,30,31,30,31,31,30,31,30,31};

Gregorian::Gregorian()
  : Date()
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
  : Date()
{
  init(y, m, d);
}

int Gregorian::year() const {
  return 0;
}

int Gregorian::month() const {
  return 0;
}

int Gregorian::day() const {
  return 0;
}

void Gregorian::init(int y, int m, int d) {
  if (!isValid(y, m , d)) {
    throw std::out_of_range("Invalid date. Check the range for days and month.");
  }

  JDN = convert_to_jdn(y, m, d);

}

long Gregorian::convert_to_jdn(int Y, int M, int D) const {
  long jdn;
  
  jdn = (1461 * (Y + 4800 + (M - 14)/12))/4 +(367 * (M - 2 - 12 * ((M - 14)/12)))/12 - (3 * ((Y + 4900 + (M - 14)/12)/100))/4 + D - 32075; // julian day number algorithm

  return jdn;
}

bool Gregorian::isValid(int y, int m, int d) const {
  if (d < 1 || m < 1) {
    return false;
  }

  return true;
}

int Gregorian::week_day() const {
  return 0;
}

int Gregorian::days_this_month() const {
  int m = month();
  if (m == 2 && leap_year()) {
    return 29;
  }
  
  return month_length[m];
}

int Gregorian::days_per_week() const {
  return 7;
}
 
int Gregorian::months_per_year() const {
  return 12;
}

void Gregorian::add_month() const {
}

void Gregorian::add_month(int i) const {

}


void Gregorian::add_year() const {

}

void Gregorian::add_year(int y) const {
  
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

long Gregorian::mod_julian_day() const {
  return this->get_jdn() - 2400001;
}

bool Gregorian::leap_year() const {
  return leap_year(year());
}
