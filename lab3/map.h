#ifndef MAP_H
#define MAP_H

#include "character.h"
#include <vector>
#include "tile.h"

namespace lab3 {
  class Map {
    protected:
      std::vector<Object> objects;
    public:
      Map();
      void load_terrain();
      void print_map();
      void add_player();
  };
}

#endif
