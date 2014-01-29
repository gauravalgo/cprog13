#ifndef TERRY_H
#define TERRY_H

#include "character.h"
#include <string>
#include "food.h"

namespace lab3 {
  class Terry : public Character {
      int count = 0;
      bool unused = true;
    public:
      Terry() : Character() {};
      Terry(int x, int y);

      std::string symbol()      { return "t"; };
      std::string description() { return "Terry the Chipmunk"; }
      
      virtual Object * perform_action();
      virtual bool can_do_action() { return unused; }

      virtual Object * tick();
  };
}
#endif
