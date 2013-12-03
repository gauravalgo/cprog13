#ifndef MAP_H
#define MAP_H

#include "object.h"
#include "character.h"
#include <vector>
#include <string>
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
      ~Map();
      
      void load_terrain();
      bool add_object_to_map(Object *);

      lab3::Player add_player();
      void move_player_up();
      lab3::Player * get_current_player();

      // Player interactions
    private:
      std::string player_move_to(Player *, int, int);
    public:
      std::string player_move_up();
      std::string player_move_down();
      std::string player_move_right();
      std::string player_move_left();

      std::string player_do_stuff_to_tile();
      std::string get_message_from_position(int, int);

      bool is_vacant(int, int);

      Object * get_object_at(int, int);
      bool drop_object_from_inventory(Object *);

  };
}

#endif
