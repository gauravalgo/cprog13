#ifndef OBJECT_H
#define OBJECT_H

#include <string>

namespace lab3 {
  class Object {
    protected:
      int x, y;
    public:
      char sym;
      Object();
      Object(int, int);

      int getX();
      int getY();

  };
}
#endif
