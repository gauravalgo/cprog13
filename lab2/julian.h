#ifndef JULIAN_H
#define JULIAN_H

#include "date.h"
#include "kattistime.h"

namespace lab2 {
  class Julian : public Date {
    private:
      void init(int, int, int);
      long convert_to_jdn() const;
    public:
      Julian();
      Julian(int y, int m, int d);
      
      bool leap_year();
      bool leap_year(int);
  };
}

#endif
