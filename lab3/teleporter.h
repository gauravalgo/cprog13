#ifndef TELEPORT_TILE_H
#define TELEPORT_TILE_H

#include "tile.h"
#include <string>

namespace lab3 {
  class Teleporter : public Tile {
    public:

      Teleporter() : Tile() {
        
      };
      Teleporter(int x, int y) : Tile(x,y) {
        
      };

      virtual bool passable()   { return true; };
      virtual bool actionable() { return true; };

      virtual short type_id()           { return 9; };
      virtual std::string symbol()      { return "O"; };
      virtual std::string description() { return "teleporter"; };
      virtual std::string action_description() { return "jumped on "; };
      virtual bool can_do_action()      { return true; }

      virtual Object * perform_action();
  };
}
#endif
