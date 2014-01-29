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
      int height = 20;
      int length = 68;
      std::string map_info;

    public:
      std::vector<Object *> objects;
      Map();
      Map(lab3::Player *);
      ~Map();
      int set_level = 0;
      virtual void load_terrain();
      bool add_object_to_map(Object *);
      void set_map_info(std::string);
      virtual std::string get_map_info();

      lab3::Player add_player();
      lab3::Player * get_current_player();

      // Player interactions

    public:
      std::string player_move_to(Player *, int, int);
      virtual std::string player_move_up();
      virtual std::string player_move_down();
      virtual std::string player_move_right();
      virtual std::string player_move_left();

      std::string player_do_stuff_to_tile();
      std::string get_message_from_position(int, int);

      bool is_vacant(int, int);

      Object * get_object_at(int, int);
      bool drop_object_from_inventory(Object *);

  };
}

#endif
