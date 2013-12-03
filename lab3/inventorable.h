#ifndef INVENTORABLE_H
#define INVENTORABLE_H

#include "object.h"

namespace lab3 {
  class Inventorable : public Object {
    protected:
    public:
      Inventorable() : Object() {};
      Inventorable(int x, int y) : Object(x, y) {};

      virtual bool passable() { return true; }
      virtual bool inventorable() { return true; }

  };
}
#endif
