#ifndef GRASS_TILE_H
#define GRASS_TILE_H

#include "tile.h"
#include <string>

namespace lab3 {
  class GrassTile : public Tile {
    public:
      GrassTile() : Tile() {};
      GrassTile(int x, int y) : Tile(x,y) {};

      virtual bool passable()   { return true; };
      virtual bool actionable() { return true;};

      virtual short type_id()           { return 6; };
      virtual std::string symbol()      { return "."; };
      virtual std::string description() { return "grass"; };
      virtual std::string action_description() { return "poked at"; };
  };
}
#endif
