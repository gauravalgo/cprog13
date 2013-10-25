#ifndef JULIAN_H
#define JULIAN_H

#include "caesar_date.h"

namespace lab2 {
  class Julian : public CaesarDate {
    public:
      Julian();
      Julian(int, int, int);
      Julian(const Date &);
  };
}

#endif
