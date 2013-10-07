#include "date.h"
#include <iostream>

using namespace lab2;

Date::Date(int m_per_year, int d_per_week, int y, int m, int d):
lyear(y),
lmonth(m),
lday(d),
ldays_per_week(d_per_week),
lmonth_per_year(m_per_year)
{
  std::cout << "Default constructor" << std::endl;
}

int Date::year() {
  return lyear;
}

int Date::month() {
  return lmonth;
}

int Date::day() {
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

Date & Date::operator++() { //prefix
  add_day();
  return *this;
}

Date & Date::operator--() {
  subtract_day();
  return *this;
}

// -----------------------
// Internal helper methods
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
}

void Date::add_month() {
  ++lmonth;
}
