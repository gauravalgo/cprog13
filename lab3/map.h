#ifndef MAP_H
#define MAP_H

#include "character.h"
#include <vector>
#include "tile.h"
#include "player.h"

namespace lab3 {
  class Map {
    protected:
      std::vector<Object> objects;
      lab3::Player * current_player;
    public:
      Map();
      void load_terrain();
      void print_map();
      void add_player();
      void move_player_up();
      lab3::Player * get_current_player();
  };
}

#endif
