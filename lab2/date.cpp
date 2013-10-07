#include "date.h"

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
  add_month(1);
}

void Date::add_month(int month) {
  lmonth += month;
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
}
