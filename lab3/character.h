#ifndef CHARACTER_H
#define CHARACTER_H
#include "object.h"
#include <vector>

namespace lab3 {
  class Character : public Object {
    private:
    protected:
    public:
      std::vector<Object *> inventory;
      Character() : Object() {};
      Character(int x, int y) : Object(x, y) {};

      virtual bool passable() { return true; }

      virtual bool add_to_inventory( Object * o );
      virtual bool drop_object( Object * );
      virtual int get_weight();
      virtual void get_player_stats(int&, int&, int&);
      
      /* Operators */
      Character& operator *= ( const Character p ) {
        return *this;
      }
  };
}
#endif
