#ifndef JULIAN_H
#define JULIAN_H

#include "middle.h"

namespace lab2 {
  class Julian : public Middle {
  protected: 
      virtual void convert_from_jdn();
      virtual long convert_to_jdn() const;
      virtual long convert_to_jdn(int, int, int) const;
      bool isValid(int, int, int) const;

    public:
      Julian();
      Julian(const Date &);
      Julian(Date * d);
      Julian(int y, int m, int d);

      Julian & operator=(Date & d);
      
      virtual bool leap_year() const;
      virtual bool leap_year(int y) const;
  };
}
#endif
