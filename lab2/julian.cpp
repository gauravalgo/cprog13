#include "julian.h"

using namespace lab2;

Julian::Julian(int y, int m, int d)
  : Date(12, 7, y, m, d)
{}

Julian::Julian()
  : Date(12, 7)
{
  // get kattis time.
  time_t mytime;
  k_time(&mytime);

  struct tm *t = gmtime(&mytime);
  int year  = t->tm_year + 1900;
  int month = t->tm_mon + 1;      // m mytimenaderna och dagarna
  int day   = t->tm_mday;         // indexerade fr =n ETTt k_time(NULL);

  init(year, month, day);
}

void Julian::init(int y, int m, int d) {
  lyear = y;
  lmonth = m;
  lday = d;
}

long Julian::convert_to_jdn() const {
  return 0; //TODO typiskt obra
}

bool Julian::leap_year(int year) {
  if (year%4==0) {
    return true;
  }
  return false;
}

bool Julian::leap_year() {
  leap_year(lyear);
}


