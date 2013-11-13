#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include <string>

namespace lab3 {
  class Player : public Object {
    public:
      Player();
      Player(int, int);
      
      virtual std::string symbol();
    
      void move_up();
      void move_down();
      void move_right();
      void move_left();
  };
}
#endif
