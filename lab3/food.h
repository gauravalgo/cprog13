#ifndef FOOD_H
#define FOOD_H

#include "object.h"
#include <string>

namespace lab3 {
  class Food : public Object {
    protected:
    public:
      Food();
      Food(int x, int y);
      Food(int x, int y, int w);

      virtual bool passable() { return true; };
      virtual short type_id();
      virtual std::string symbol();
      virtual std::string description();

    };
}
#endif
