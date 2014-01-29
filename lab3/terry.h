#ifndef TERRY_H
#define TERRY_H

#include "character.h"
#include <string>
#include "food.h"

namespace lab3 {
  class Terry : public Character {
    public:
      int count = 0;
      Terry() : Character() {};
      Terry(int x, int y);

      std::string symbol()      { return "t"; };
      std::string description() { return "Terry the Chipmunk"; }
      
      virtual Object * perform_action();

      virtual Object * tick();
  };
}
#endif
