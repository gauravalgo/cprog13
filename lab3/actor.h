#ifndef ACTOR_H
#define ACTOR_H

#include "object.h"
#include <string>
#include <vector>

namespace lab3 {
  class Actor : public Object {
    private:
    public:
      std::vector<Object *> inventory;
      Actor();
      Actor(int, int);
  
      virtual void get_actor_stats(int&, int&, int&);
      virtual short type_id() {
        return 4;
      }
      virtual std::string symbol() { return "x"; };
    
      /* Operators */
      Actor& operator *= ( const Actor p ) {
        return *this;
      }

      virtual bool add_to_inventory( Object * o );
      virtual int get_weight();

      virtual bool drop_object( Object * );
  };
}
#endif
