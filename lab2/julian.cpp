#include "julian.h"
#include <stdexcept>
using namespace lab2;

Julian::Julian() {
  int days_since_unix_time = k_time(0) / (24*60*60);
  JDN = days_since_unix_time + 40587+2400001;
  //mod från 1858
  convert_from_jdn();
  
}

Julian::Julian(const Date & d){
  if (this == &d) {
    return;
  }
  JDN = d.get_jdn();
  //JDN = convert_to_jdn(d.year(), d.month(), d.day());
  convert_from_jdn();
}

Julian & Julian::operator=(Date & d) {
  if (this == &d) {
    return *this;
  }
  JDN = d.get_jdn();
  convert_from_jdn();
  return *this;
}

Julian::Julian(Date * d){
  JDN = d->get_jdn();
  //JDN = convert_to_jdn(d->year(), d->month(), d->day());
  convert_from_jdn();
}

Julian::Julian(int y, int m, int d) {
  if (!isValid(y, m , d)) {
    throw std::out_of_range("Invalid date. Check the range for days and month.");
  }

  JDN = convert_to_jdn(y, m, d);
  convert_from_jdn();
}

bool Julian::isValid(int y, int m, int d) const {
  if (m < 0 || d > get_month_length(y, m) || d < 1)
    return false;
  return true;
}

bool Julian::leap_year() const {
  leap_year(year());
}

bool Julian::leap_year(int y) const {
  if (y%4==0) return true;
  return false;
}
long Julian::convert_to_jdn() const{
  return convert_to_jdn(lyear, lmonth, lday);
}
long Julian::convert_to_jdn(int Y, int M, int D) const {
  long jdn;
  jdn = 367L*Y -7 * (Y+5001L+(M-9)/7)/4+275*M/9+D+1729777L;
  return jdn;
}

// http://www8.cs.umu.se/~isak/Snippets/jdn.c
void Julian::convert_from_jdn() {
  
  long jdn = get_jdn();
  long x, z, m, d, y;
  long daysPer400Years = 146097L;
  long fudgedDaysPer4000Years = 1460970L + 31;

  // if (julian < 0)                 /* set Julian flag if auto set */
  //   julian = (jdn <= LASTJULJDN);

  x = jdn + 68569L;
  if (true) {
    x += 38;
    daysPer400Years = 146100L;
    fudgedDaysPer4000Years = 1461000L + 1;
   }

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
