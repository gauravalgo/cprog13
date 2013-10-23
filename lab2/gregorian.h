#ifndef GREGORIAN_H
#define GREGOIRAN_H

#include "date.h"
#include "kattistime.h"

namespace lab2 {
  class Gregorian : public Date {
    private:
      void subtract_month();
    protected:
      int lyear;
      int lmonth;
      int lday;

      void init(int, int, int);
      bool isValid(int, int, int) const;
      long convert_to_jdn(int, int, int) const;
      long convert_to_jdn() const;

      void convert_to_gregorian();

    public:
      Gregorian();
      Gregorian(int y, int m, int d);

      int year() const;
      int month() const;
      int day() const;

      std::string week_day_name() const;
      std::string month_name() const;
      int days_per_week() const { return 7; };
      int days_this_month() const;
      int months_per_year() const { return 12; };
      
      int get_month_length(int) const;
      int get_month_length(int, int) const;


      void add_day();
      void add_day(int);
      void subtract_day();
      
      void add_month();
      void add_month(int);

      void add_year();
      void add_year(int);
      
      bool leap_year(int) const;
      bool leap_year() const;

      long mod_julian_day() const;
  };
}
#endif
