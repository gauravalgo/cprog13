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
  
      short type_id() { return 4; }
      std::string symbol();
  };
}
#endif
