#ifndef TREE_H
#define TREE_H

#include "tile.h"
#include <string>

namespace lab3 {
  class TreeTile : public lab3::Tile {
    public:
      TreeTile();
      TreeTile(int, int);
      std::string symbol() {
        return "T";
      }
      
      short type_id() { return 3; }
      virtual bool passable() { return false; }
  };
}
#endif
