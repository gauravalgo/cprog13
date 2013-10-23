#include "gregorian.h"
#include <stdexcept>
#include <assert.h>
#include <math.h>

using namespace lab2;

const int month_length[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
const std::string WEEK_DAY_NAMES[8] = { "", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
const std::string MONTH_NAMES[13] = {"", "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};


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
  if (m < 1 || m > 12) {
    throw std::out_of_range("Invalid date. Check the range for days and month.");
  }
  if (m == 2 && leap_year(y)) {
    return 29;
  }

  return month_length[m - 1];
}

int Gregorian::get_month_length(int m) const {
  assert(year()>0);
  return get_month_length(year(), m);
}

std::string Gregorian::week_day_name() const {
  return WEEK_DAY_NAMES[week_day()];
}

std::string Gregorian::month_name() const {
  return MONTH_NAMES[month()];
}

int Gregorian::days_this_month() const {
  get_month_length(month());
}

void Gregorian::subtract_month() {

  lmonth--;

  if (lmonth < 1) {
    lmonth = 12;
    lyear--;
  }

  JDN = convert_to_jdn();
}

void Gregorian::add_month() {
  int m = (lmonth + 1) % 12;

  if (get_month_length(m) < lday) {
    JDN += 30;
    convert_to_gregorian();
  } else {
    lmonth++;
    if (lmonth > 12) {
      lmonth = 1;
      ++lyear;
    }
    JDN = convert_to_jdn();
  }
}

void Gregorian::add_month(int times) {
  for (int i = 0; i < std::abs(times); i++) {
    if (times > 0) {
      add_month();
    } else {
      subtract_month();
    }
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

void Gregorian::modify_year(int y) {
  if (month() == 2 && day() == 29) {
    lday = 28;
  }
  lyear += y;
  JDN = convert_to_jdn();
}

void Gregorian::add_year() {
  modify_year(1);
}

void Gregorian::add_year(int y) {
  for (int i = 0; i < std::abs(y); i++) {
    if (y > 0) {
      modify_year(1);
    } else {
      modify_year(-1);
    }
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
