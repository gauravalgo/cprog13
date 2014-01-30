#ifndef CHARACTER_H
#define CHARACTER_H

#include "object.h"
#include <vector>
#include <string>

namespace lab3 {
  class Character : public Object {
    private:
    protected:
    public:
      std::vector<Object *> inventory;
      Character();
      Character(int x, int y) : Object(x, y) {};
      virtual ~Character();
      
      virtual bool add_to_inventory( Object * o );
      virtual bool drop_object( Object * );
      virtual int get_weight();
      virtual void get_player_stats(int&, int&, int&);
      virtual std::string symbol();

      virtual bool can_do_action()              { return true; }
      virtual std::string action_description()  { return "talked to"; }
      virtual bool actionable()                 { return true; }
      virtual bool passable()                   { return true; }
      virtual short type_id()                   { return 12; }
      
      /* Operators */
      Character& operator *= ( const Character p ) {
        return *this;
      }
  };
}
#endif
