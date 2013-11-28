#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include <string>
#include <vector>
#include "actor.h"

namespace lab3 {
  class Player : public Actor {
    private:
    public:
      Player();
      Player(int, int);
  
      virtual short type_id() { return 4; }
      virtual std::string symbol() { return "X"; };
  };
}
  
#endif
