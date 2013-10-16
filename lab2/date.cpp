#include "date.h"

using namespace lab2;

Date::Date()
{}

Date::Date(int m_per_year, int d_per_week) :
  ldays_per_week(d_per_week),
  lmonth_per_year(m_per_year)
{}

Date::Date(int m_per_year, int d_per_week, int y, int m, int d):
lyear(y),
lmonth(m),
lday(d),
ldays_per_week(d_per_week),
lmonth_per_year(m_per_year)
{
  // JDN = convert_to_jdn(y, m, d) - MODIFED_JULIAN_DAY_CONSTANT;
}

int Date::year() const { return lyear; }
int Date::month() const { return lmonth; }
int Date::day() const { return lday; }

/* 1 = monday, etc */
int Date::week_day() {
  return 3;
}

int Date::days_per_week() {
  return ldays_per_week;
}

int Date::months_per_year() {
  return lmonth_per_year;
}

// ---------
// Operators
Date & Date::operator++() { //prefix
  add_day();
  return *this;
}

Date & Date::operator--() {
  subtract_day();
  return *this;
}

Date & Date::operator-=(int days) {
  for (int i = 0; i < days; i++) {
    subtract_day();
  }
  return *this;
}

Date & Date::operator+=(int days) {
  for (int i = 0; i < days; i++) {
    add_day();
  }
  return *this;
}

void Date::add_year() {
  add_year(1);
}

void Date::add_year(int years) {
  lyear += years;
}

void Date::add_month() {
  lmonth += 1;
  if (lmonth > months_per_year()) {
    lmonth = 1;
    add_year();
  }
}

void Date::add_month(int month) {
  if (month > 0) {
    for (int i = 0; i < month; i++) {
      add_month();
    }
  } else {
    for (int i = 0; i > month; i--) {
      subtract_month();
    }
  }
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
  return JDN - MODIFED_JULIAN_DAY_CONSTANT;
}

// ---------
// printouts
std::ostream& lab2::operator<<(std::ostream & os, const Date & d) {
  os << d.year() << "-" << d.month() << "-" << d.day() <<"\n";
}

// -----------------------
// Internal/private helper methods
void Date::subtract_day() {
  --lday;
  if (lday < 1) {
    lday = days_this_month();
    subtract_month();
  }
}

void Date::add_day() {
  lday++;
  if (lday > days_this_month()) {
    lday = 1;
    add_month();
  }
}

int Date::days_this_month() const {
  return 31;
}

void Date::subtract_month() {
  --lmonth;
  if (lmonth < 0) {
    lmonth = months_per_year();
    lyear -= 1;
  }
}


bool Date::leap_year(int) const {
  return false; // TODO!! should be pure virutal
}

bool Date::leap_year() const {
  return false; // TODO!! should be pure virutal
}
