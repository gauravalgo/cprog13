#ifndef BUTTON_H
#define BUTTON_H

#include "object.h"
#include <string>

namespace lab3 {
  class Button : public Object {
    protected:
      bool pressed;
    public:
      Button() : Object() {
        pressed = false;
      };
      Button( int x, int y ) : Object(x,y) {
        pressed = false;
      };


      virtual std::string symbol()      {
        if (pressed) {
          return "b";
        }
        return "B";
      };
      virtual short type_id()           { return 7; };
      virtual std::string description() { return "button"; };

      virtual std::string action() {
        if (pressed) {
          return "have already pressed";
        }
        pressed = true;
        return "pressed";
      };

      virtual bool actionable() { return true; };
      virtual bool passable()   { return true; };
  };
}
#endif
