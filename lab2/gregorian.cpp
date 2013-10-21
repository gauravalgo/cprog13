#include "gregorian.h"
#include <stdexcept>
#include <assert.h>

using namespace lab2;

const int month_length[13] = {-1, 31,28,31,30,31,30,31,31,30,31,30,31};

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

// http://www8.cs.umu.se/~isak/Snippets/jdn.c
void Gregorian::convert_to_gregorian() {
  
  long jdn = get_jdn();
  long x, z, m, d, y;
  long daysPer400Years = 146097L;
  long fudgedDaysPer4000Years = 1460970L + 31;

  // if (julian < 0)                 /* set Julian flag if auto set */
  //   julian = (jdn <= LASTJULJDN);

  x = jdn + 68569L;
  // if ( julian  )
  // {
  //   x += 38;
  //   daysPer400Years = 146100L;
  //   fudgedDaysPer4000Years = 1461000L + 1;

  // }
  z = 4 * x / daysPer400Years;
  x = x - (daysPer400Years * z + 3) / 4;
  y = 4000 * (x + 1) / fudgedDaysPer4000Years;
  x = x - 1461 * y / 4 + 31;
  m = 80 * x / 2447;
  d = x - 2447 * m / 80;
  x = m / 11;
  m = m + 2 - 12 * x;
  y = 100 * (z - 49) + y + x;

  lyear = (int)y;
  lmonth = (int)m;
  lday = (int)d;
}

int Gregorian::year() const { return lyear; }

int Gregorian::month() const { return lmonth; }

int Gregorian::day() const { return lday; }

void Gregorian::init(int y, int m, int d) {
  if (!isValid(y, m , d)) {
    throw std::out_of_range("Invalid date. Check the range for days and month.");
  }

  JDN = convert_to_jdn(y, m, d);
  convert_to_gregorian();
}

long Gregorian::convert_to_jdn(int Y, int M, int D) const {
  long jdn;
  
  jdn = (1461 * (Y + 4800 + (M - 14)/12))/4 +(367 * (M - 2 - 12 * ((M - 14)/12)))/12 - (3 * ((Y + 4900 + (M - 14)/12)/100))/4 + D - 32075; // julian day number algorithm

  return jdn;
}

long Gregorian::convert_to_jdn() const {
  return convert_to_jdn(lyear, lmonth, lday);
}

bool Gregorian::isValid(int y, int m, int d) const {
  if (d < 1 || m < 1 || m > months_per_year() || d > get_month_length(y, m)) {
    return false;
  }

  return true;
}

int Gregorian::get_month_length(int y,int m) const {
  if (m == 2 && leap_year(y)) {
    return 29;
  }
  return month_length[m];
}

int Gregorian::get_month_length(int m) const {
  assert(year()>0);
  return get_month_length(year(), m);
}

int Gregorian::week_day() const {
  return 0;
}

int Gregorian::days_this_month() const {
  get_month_length(month());
}

int Gregorian::days_per_week() const {
  return 7;
}
 
int Gregorian::months_per_year() const {
  return 12;
}

void Gregorian::add_month() {
  int year = lyear;
  int month = lmonth;
  int day = lday;

  if (get_month_length(( lmonth +1) % 12) > day) {
    JDN = convert_to_jdn(year, month + 1 , day);
  } else {
    add_day(30);
  }

  convert_to_gregorian();
}

void Gregorian::add_month(int times) {
  for (int i = 0; i < times; i++) {
    add_month();
  }
}

void Gregorian::add_day() {
  JDN++;
  convert_to_gregorian();
}

void Gregorian::add_day(int days) {
  JDN += days;
  convert_to_gregorian();
}

void Gregorian::subtract_day() {
  JDN--;
  convert_to_gregorian();
}

void Gregorian::add_year() {
  if (month() == 2 && day() == 29) {
    lday = 28;
  }
  lyear++;
  JDN = convert_to_jdn();
}

void Gregorian::add_year(int y) {
  if (y > 0) {
    for (int i = 0; i < y; i++) {
      add_year();
    }
  } else {
    lyear += y;
  }

  JDN = convert_to_jdn();
  
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
  assert(year() > 0);
  return leap_year(year());
}
