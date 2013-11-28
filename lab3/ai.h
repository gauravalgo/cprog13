#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include <string>
#include <vector>
#include "actor.h"

namespace lab3 {
  class AI : public Actor {
    private:
    public:
      AI();
      AI(int, int);
  
      virtual short type_id() { return 6; }
      virtual std::string symbol() { return "X"; };
      virtual std::string description() { return "cute crit"; }
  };
}
  
#endif
