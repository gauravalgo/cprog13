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

      void set_position(int x, int y);
      virtual bool passable() { return true; };
  };
}
#endif
