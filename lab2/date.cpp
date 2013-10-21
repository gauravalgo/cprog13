#include "date.h"

using namespace lab2;

Date::Date()
{}

long Date::get_jdn() const {
  return JDN;
}

// ---------
// Operators
Date & Date::operator++() { //prefix
  JDN++;
  return *this;
}

Date & Date::operator--() {
  JDN--;
  return *this;
}

Date & Date::operator-=(int days) {
  JDN -= days;
  return *this;
}

Date & Date::operator+=(int days) {
  JDN += days;
  return *this;
}

// Comperators
bool Date::operator==(const Date & x) const {
  return (*this-x) == 0;
}

bool Date::operator!=(const Date & x) const {
  return (*this - x ) != 0;
}

bool Date::operator>(const Date & x) const {
  return (*this -x ) > 0;
}

bool Date::operator>=(const Date & x) const {
  return (*this - x) >= 0;
}

bool Date::operator<=(const Date & x) const {
  return (*this - x) <= 0;
}

bool Date::operator<(const Date & x) const {
  return (*this - x) < 0;
}

int Date::operator-(const Date & x ) const {
  return this->mod_julian_day() - x.mod_julian_day();
}

long Date::mod_julian_day() const {
  return JDN;// - MODIFED_JULIAN_DAY_CONSTANT;
}

// ---------
// printouts
std::ostream& lab2::operator<<(std::ostream & os, const Date & d) {
  os << d.year() << "-" << d.month() << "-" << d.day() <<"\n";
}

// -----------------------
// Internal/private helper methods
// void Date::subtract_day() {
//   --lday;
//   if (lday < 1) {
//     lday = days_this_month();
//     subtract_month();
//   }
// }
// 
// void Date::add_day() {
//   lday++;
//   if (lday > days_this_month()) {
//     lday = 1;
//     add_month();
//   }
// }
// 
// int Date::days_this_month() const {
//   return 31;
// }

// void Date::subtract_month() {
//   --lmonth;
//   if (lmonth < 0) {
//     lmonth = months_per_year();
//     lyear -= 1;
//   }
// }
// 
// 
// bool Date::leap_year(int) const {
//   return false; // TODO!! should be pure virutal
// }
// 
// bool Date::leap_year() const {
//   return false; // TODO!! should be pure virutal
// }
