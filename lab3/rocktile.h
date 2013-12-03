#ifndef ROCK_H
#define ROCK_H

#include "tile.h"
#include <string>

namespace lab3 {
  class RockTile : public lab3::Tile {
    public:
      RockTile();
      RockTile(int, int);
      short type_id() { return 2; };
      std::string symbol() {
        return "R";
      };
  };
}
#endif
