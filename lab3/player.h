#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include <string>
#include <vector>

namespace lab3 {
  class Player : public Character {
    private:
    public:
      Player();
      Player(int, int);
  
      std::string symbol();
      short type_id()                           { return 4; }
  };
}
#endif
