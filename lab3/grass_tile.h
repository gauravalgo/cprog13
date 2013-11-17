#ifndef GRASS_TILE_H
#define GRASS_TILE_H

#include "tile.h"
#include <string>

namespace lab3 {
  class GrassTile : public Tile {
    public:
      GrassTile() : Tile() {};
      GrassTile(int x, int y) : Tile(x,y) {};

      virtual bool passable() { return true; };

      virtual short type_id() { return 6; };
      virtual std::string symbol() { return "."; };
  };
}
#endif
