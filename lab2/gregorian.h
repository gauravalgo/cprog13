#ifndef GREGORIAN_H
#define GREGOIRAN_H

#include "caesar_date.h"

namespace lab2 {
  class Gregorian : public CaesarDate {
    public:
      Gregorian();
      Gregorian(const Date &);
      Gregorian(int y, int m, int d);
  };
}
#endif
