#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"

namespace lab3 {
  class Player : public Object {
    protected:
    public:
      Player();
      Player(int, int);
  };
}
#endif
