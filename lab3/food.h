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
      virtual std::string description() { return "Food"; }
      virtual std::string action_description() { return "ate"; }
      virtual bool can_do_action() { return true; };

      virtual Object * perform_action();

      virtual int get_hp()      { return 10; };
      virtual int get_hunger()  { return 3; };
      virtual int get_weight()  { return 1; };
    };
}
#endif
