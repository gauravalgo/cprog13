#include "date.h"

using namespace lab2;

Date::Date(){}

Date::Date(const Date & d) {
  JDN = d.get_jdn();
}

Date::Date(Date * d) {
  JDN = d->get_jdn();
}

int Date::year() const {
  return lyear;
}
int Date::month() const {
  return lmonth;
}
int Date::day() const {
  return lday;
}

long Date::get_jdn() const {
  return JDN;
}

int Date::week_day() const {
  // mod julian day ( 1858/11/17 är en onsdag, däröfr plus 3)
  int weekday = (mod_julian_day() + 3) % days_per_week();

  if (weekday < 1) {
    weekday += 7;
  }
  return weekday;
}

// ---------
// Operators
Date & Date::operator++() { //prefix
  add_day();
  return *this;
}

Date & Date::operator--() {
  add_day(-1);
  return *this;
}

Date & Date::operator-=(int days) {
  for (int i = 0; i < std::abs(days); i++) {
    if (days < 0) {
      ++*this;
    } else {
      --*this;
    }
  }
  return *this;
}

Date & Date::operator+=(int days) {
  return *this -=- days;
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
  return mod_julian_day() - x.mod_julian_day();
}

long Date::mod_julian_day() const {
  return JDN;// - MODIFED_JULIAN_DAY_CONSTANT;
}

// ---------
// printouts
std::ostream& lab2::operator<<(std::ostream & os, const Date & d) {
  os << d.year() << "-";
  if(d.month() < 10) {
    os << "0" << d.month();
  } else {
    os << d.month();
  }

  os << "-";

  if (d.day() < 10) {
    os << "0" << d.day();
  } else {
    os << d.day();
  }
}
