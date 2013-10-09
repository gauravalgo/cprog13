#ifndef JULIAN_H
#define JULIAN_H

#include "date.h"

namespace lab2 {
  class Julian : public Date {
    public:
      Julian();
      Julian(int y, int m, int d);
  };
}

#endif
