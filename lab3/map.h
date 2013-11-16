#ifndef MAP_H
#define MAP_H

#include "object.h"
#include "character.h"
#include <vector>
#include "tile.h"
#include "player.h"

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
      void print_object(Object *);

      lab3::Player add_player();
      void move_player_up();
      lab3::Player * get_current_player();

      // Player interactions
    private:
      void player_move_to(Player *, int, int);
    public:
      void player_move_up();
      void player_move_down();
      void player_move_right();
      void player_move_left();

      bool is_vacant(int, int);

      Object * get_object_at(int, int);

  };
}

#endif
