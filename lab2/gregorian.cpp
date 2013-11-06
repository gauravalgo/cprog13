#include "gregorian.h"
#include <stdexcept>
using namespace lab2;

Gregorian::Gregorian() {
  // std::cout << "Gregorian::Gregorian()" << std::endl;
  int days_since_unix_time = k_time(0) / (24*60*60);
  JDN = days_since_unix_time + 40587+2400001;
  // std::cout << "Gregoirian() Default Constructor: " << lyear<< year() <<std::endl;
}

Gregorian::Gregorian(const Date & d) {
  // std::cout << "Gregorian::Gregorian(Date & d)" << std::endl;
  if (this == &d) {
    return;
  }
  JDN = d.get_jdn();
}

Gregorian & Gregorian::operator=(const Date &d){
  // std::cout << "Gregorian::operator=(Date & d)" << std::endl;
  if (this == &d) {
    return *this;
  }

  JDN = d.get_jdn();
  return *this;
}

Gregorian::Gregorian(int y, int m, int d) {
  if (!isValid(y, m , d)) {
    throw std::out_of_range("Invalid date. Check the range for days and month.");
      
  }
  JDN = convert_to_jdn(y, m, d);
}

Gregorian::Gregorian( Date && d) {
  std::cout << "Gregorian::Gregorian(Date && d)" << std::endl;
}

bool Gregorian::isValid(int y, int m, int d) const {
  if (m < 0 || d > get_month_length(y, m) || d < 1)
    return false;
  return true;
}

bool Gregorian::leap_year() const {
	leap_year(year());
}

bool Gregorian::leap_year(int year) const {
  if (year % 400 == 0) return true; 
  if (year % 100 == 0) return false; 
  if (year % 4 == 0) return true; 
  return false;
}

long Gregorian::convert_to_jdn(int Y, int M, int D) const {
  long jdn;
  
  jdn = (1461 * (Y + 4800 + (M - 14)/12))/4 +(367 * (M - 2 - 12 * ((M - 14)/12)))/12 - (3 * ((Y + 4900 + (M - 14)/12)/100))/4 + D - 32075; // julian day number algorithm

  return jdn;
}

// http://www8.cs.umu.se/~isak/Snippets/jdn.c
void Gregorian::convert_from_jdn(long jdn, int & year, int & month, int & day) const 
{
  
  long x, z, y, m ,d;
  long daysPer400Years = 146097L;
  long fudgedDaysPer4000Years = 1460970L + 31;

  // if (julian < 0)                 /* set Julian flag if auto set */
  //   julian = (jdn <= LASTJULJDN);

  x = jdn + 68569L;
  if (false) {
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

  year = (int)y;
  month = (int)m;
  day = (int)d;
}