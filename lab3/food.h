#ifndef FOOD_H
#define FOOD_H

#include "inventorable.h"
#include <string>

namespace lab3 {
  class Food : public Inventorable {
    protected:
    public:
      Food();
      Food(int x, int y);

      virtual short type_id();
      virtual std::string symbol();
      virtual std::string description();
      virtual bool can_do_action() { return true; };

      virtual Object * perform_action();
    };
}
#endif
