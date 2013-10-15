#ifndef GREGORIAN_H
#define GREGOIRAN_H

#include "date.h"
#include "kattistime.h"

namespace lab2 {
  class Gregorian : public Date {
    private:
      void init(int, int, int);
    public:
      Gregorian();
      Gregorian(int y, int m, int d);
  };
}
#endif
