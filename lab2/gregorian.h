#ifndef GREGORIAN_H
#define GREGOIRAN_H

#include "date.h"
#include "kattistime.h"

namespace lab2 {
  class Gregorian : public Date {
    private:
      void init(int, int, int);
      bool isValid(int, int, int);
      long convert_to_jdn() const;
    public:
      Gregorian();
      Gregorian(int y, int m, int d);
      int days_this_month() const;
      bool leap_year() const;
      bool leap_year(int) const;
  };
}
#endif
