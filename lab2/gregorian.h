#ifndef GREGORIAN_H
#define GREGOIRAN_H

#include "date.h"
#include "kattistime.h"

namespace lab2 {
  class Gregorian : public Date {
    protected:
      void init(int, int, int);
      bool isValid(int, int, int) const;
      long convert_to_jdn(int, int, int) const;
    public:
      Gregorian();
      Gregorian(int y, int m, int d);

      int year() const;
      int month() const;
      int day() const;

      int week_day() const;
      int days_per_week() const;
      int days_this_month() const;
      int months_per_year() const;

      void add_month() const;
      void add_month(int) const;

      void add_year() const;
      void add_year(int) const;

      bool leap_year(int) const;
      bool leap_year() const;

      long mod_julian_day() const;
  };
}
#endif
