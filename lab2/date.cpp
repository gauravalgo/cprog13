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
