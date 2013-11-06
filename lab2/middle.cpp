#include "middle.h"
#include <stdexcept>
#include <assert.h>
#include <math.h>

#include "kattistime.h"
using namespace lab2;

const int month_length[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
const std::string WEEK_DAY_NAMES[8] = { "", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
const std::string MONTH_NAMES[13] = {"", "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};

/*Middle & Middle::operator=(Date &d){
  JDN = convert_to_jdn(d.year(), d.month(), d.day());
  lyear = d.year();
  lmonth = d.month();
  lday = d.day();
  return *this;
}*/

int Middle::year() const {
  int y, m, d;
  long jdn = get_jdn();
  convert_from_jdn(jdn, y, m, d);

  return y;
}

int Middle::month() const {
  int y, m, d;
  long jdn = get_jdn();
  convert_from_jdn(jdn, y, m, d);

  return m;
}

int Middle::day() const {
  int y, m, d;
  long jdn = get_jdn();
  convert_from_jdn(jdn, y, m, d);

  return d;
}

std::string Middle::week_day_name() const {
  return WEEK_DAY_NAMES[week_day()];
}

std::string Middle::month_name() const {
  return MONTH_NAMES[month()];
}

int Middle::days_this_month() const {
  return get_month_length(month());
}

void Middle::subtract_month() {
  int year, month, day;
  convert_from_jdn(get_jdn(), year, month, day);
  
  month = (month - 1) % 13;
  
  if (month == 0) { month = 12; year--;}
  
  if (get_month_length(year, month) < day ){
    JDN -= 30;
  } else {
    JDN = convert_to_jdn(year, month, day);
  }
}

void Middle::add_month() {
  int year, month, day;
  convert_from_jdn(get_jdn(), year, month, day);

  month = (month + 1) % 13;

  if (month==0) { month++; year++;}

  if (get_month_length(year, month) < day) {
    JDN += 30;
  } else {
    JDN = convert_to_jdn(year, month, day);
  }
}

void Middle::add_month(int times) {
  for (int i = 0; i < std::abs(times); i++) {
    if (times > 0) {
      add_month();
    } else {
      subtract_month();
    }
  }
}

void Middle::add_day() {
  JDN++;
}

void Middle::add_day(int days) {
  JDN += days;
}

int Middle::get_month_length(int m) const {
  int year, month, day;
  convert_from_jdn(get_jdn(), year, month, day);
  // std::cout << "Middle::get_month_length month " << month << std::endl;
  assert(year>0);

  return get_month_length(year, m);
}

int Middle::get_month_length(int y, int m) const {
  if (m < 1 || m > 12) {
    throw std::out_of_range("Invalid date. Check the range for days and month.");
  }
  if (m == 2 && leap_year(y)) {
    return 29;
  }

  return month_length[m - 1];
}
void Middle::add_year() {
  add_year(1);
}

void Middle::add_year(int y) {
  int year, month, day;
  convert_from_jdn(get_jdn(), year, month, day);
  
  year += y;

  if (month == 2 && day == 29 && !leap_year(year)) {
    day = 28;
  }

  JDN = convert_to_jdn(year, month, day);
}

long Middle::mod_julian_day() const {
  return this->get_jdn() - 2400001;
}