#include "date.h"

using namespace lab2;

Date::Date(int m_per_year, int d_per_week, int y, int m, int d):
lyear(y),
lmonth(m),
lday(d),
ldays_per_week(d_per_week),
lmonth_per_year(m_per_year)
{
  JDN = convert_to_jdn(y, m, d) - MODIFED_JULIAN_DAY_CONSTANT;
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

/* 1 = monday, etc */
int Date::week_day() {
  return 3;
}

int Date::days_per_week() {
  return ldays_per_week;
}

int Date::days_this_month() {
  return 31;
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
bool Date::operator==( Date x) {
  return (days_diff(x) == 0);
}

bool Date::operator!=(Date x) {
  return (days_diff(x) != 0);
}

bool Date::operator>(Date x) {
  return (days_diff(x) > 0);
}

bool Date::operator>=(Date x) {
  return (days_diff(x) >= 0);
}

bool Date::operator<=(Date x) {
  return (days_diff(x) <= 0);
}

bool Date::operator<(Date x) {
  return (days_diff(x) < 0);
}

int Date::operator-( Date x ) {
  return days_diff(x);
}

int Date::days_diff(Date x) {
  int diff = 0;
  int year_diff = (lyear - x.year());
  
  int month_diff = (lmonth - x.month())+year_diff*months_per_year();
  int day_diff = (lday - x.day());

  diff = day_diff + days_this_month()*month_diff;
  return (diff);
}

long Date::mod_julian_day() {
  return JDN;
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

void Date::subtract_month() {
  --lmonth;
  if (lmonth < 0) {
    lmonth = months_per_year();
    lyear -= 1;
  }
}

long Date::convert_to_jdn(int y, int m, int d) {
  long jdn;
  int Y = lyear;
  int M = lmonth;
  int D = lday;
  
  jdn = (1461 * (Y + 4800 + (M - 14)/12))/4 +(367 * (M - 2 - 12 * ((M - 14)/12)))/12 - (3 * ((Y + 4900 + (M - 14)/12)/100))/4 + D - 32075; // julian day number algorithm

  return jdn;
}
