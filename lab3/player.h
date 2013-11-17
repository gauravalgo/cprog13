#ifndef PLAYER_H
#define PLAYER_H

#include "object.h"
#include <string>
#include <vector>

namespace lab3 {
  class Player : public Object {
    private:
    public:
      std::vector<Object *> inventory;
      Player();
      Player(int, int);
  
      void get_player_stats(int&, int&, int&);
      short type_id() {
        return 4;
      }
      std::string symbol();
    
      void move_down();
      void move_right();
      void move_left();

      /* Operators */
      Player& operator *= ( const Player p ) {
        return *this;
      }

      bool add_to_inventory( Object * o );
      int get_weight();
  };
}
  
#endif
