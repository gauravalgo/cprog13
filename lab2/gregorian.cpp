#include "gregorian.h"

using namespace lab2;

Gregorian::Gregorian()
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

Gregorian::Gregorian(int y, int m, int d)
  : Date(12, 7, y, m , d)
{}

void Gregorian::init(int y, int m, int d) {
  lyear = y;
  lmonth = m;
  lday = d;
}
