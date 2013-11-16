#ifndef TILE_H
#define TILE_H

#include "object.h"
#include <string>

namespace lab3 {
  class Tile : public Object {
    protected:
    public:
      Tile();
      Tile(int x, int y);

      virtual std::string symbol();
  };
}
#endif
