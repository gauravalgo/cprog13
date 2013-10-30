#ifndef GREGORIAN_H
#define GREGOIRAN_H

#include "julian.h"

namespace lab2 {
  class Gregorian : public Julian {
    public:
      Gregorian();
      Gregorian(const Date &);
      Gregorian(int y, int m, int d);

      virtual bool leap_year() const;
      virtual bool leap_year(int y) const;
  };
}
#endif
