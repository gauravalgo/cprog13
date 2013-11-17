#ifndef OBJECT_H
#define OBJECT_H

#include <string>

namespace lab3 {
  class Object {
    protected:
    public:
      int x, y;
      char sym;
      Object();
      Object(int, int);

      int getX();
      int getY();

      virtual std::string symbol();
      virtual short type_id();
      virtual std::string description();
      virtual std::string action_description() { return "looked at"; };


      void set_position(int x, int y);
      virtual bool passable()       { return false; }; // can we walk over it?
      virtual bool inventorable()   { return false; }; // can we pick it up?
      virtual bool actionable()     { return false; }; // does it have an action we might be able to perform?
      virtual bool can_do_action()  { return false; }; // can we perform the action? Or have we already pressed the buttin for example.

      virtual Object * perform_action() { new Object(30,30); };
  };
}
#endif
