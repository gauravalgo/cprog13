#ifndef Middle_H
#define Middle_H

#include "date.h"
#include "kattistime.h"

namespace lab2 {
  class Middle : public Date {
    protected:
      int lyear;
      int lmonth;
      int lday;

      void subtract_month();

    public:
      Middle();
      Middle(const Date &);
      Middle(Date *);
      Middle(int y, int m, int d);

      int year() const;
      int month() const;
      int day() const;

      std::string week_day_name() const;
      std::string month_name() const;
      int days_per_week() const { return 7; };
      int days_this_month() const;
      int months_per_year() const { return 12; };
      
      void add_day();
      void add_day(int);
      void subtract_day();

      int get_month_length(int) const;
      int get_month_length(int, int) const;

      void add_month();
      void add_month(int);

      void add_year();
      void add_year(int);

      virtual bool leap_year(int) const = 0;
      virtual bool leap_year() const = 0;

      virtual long convert_to_jdn() const = 0;
      virtual void convert_from_jdn() = 0;
      virtual long convert_to_jdn(int, int, int) const = 0;
      long mod_julian_day() const;
  };
}
#endif
