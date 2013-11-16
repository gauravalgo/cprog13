#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include <string>

namespace lab3 {
  class Player : public Object {
    public:
      Player();
      Player(int, int);
      
      short type_id() {
        return 4;
      }
      std::string symbol();
    
      void move_down();
      void move_right();
      void move_left();

      /* Operators */
      Player& operator *= ( const Player p ) {
        return *this;
      }
  };
}
#endif
