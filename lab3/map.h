#ifndef MAP_H
#define MAP_H

#include "object.h"
#include "character.h"
#include <vector>
#include "tile.h"
#include "player.h"
#include <memory.h> //shared_ptr

namespace lab3 {
  class Map {
    protected:
      lab3::Player * current_player;
    public:
      std::vector<Object *> objects;
      Map();
      Map(lab3::Player *);
      
      void load_terrain();
      void print_map();
      lab3::Player add_player();
      void move_player_up();
      lab3::Player * get_current_player();

  };
}

#endif
