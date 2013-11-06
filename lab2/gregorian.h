#ifndef GREGORIAN_H
#define GREGORIAN_H

#include "middle.h"

namespace lab2 {
  class Gregorian : public Middle {
  	protected:
  		virtual long convert_to_jdn(int, int, int) const;
      virtual void convert_from_jdn(long, int &, int &, int &) const;
		  bool isValid(int, int, int) const;

    public:
		  Gregorian();
		  Gregorian( const Date &);
      Gregorian( Date &&);
      Gregorian & operator=(const Date &);
		  Gregorian(int y, int m, int d);

		  virtual bool leap_year(int y) const;
		  virtual bool leap_year() const;
  };
}
#endif
