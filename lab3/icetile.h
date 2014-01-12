#ifndef ICE_H
#define ICE_H

#include "tile.h"
#include <string>

namespace lab3 {
  class IceTile : public lab3::Tile {
    public:
      IceTile();
      IceTile(int, int);
      std::string symbol() {
        return "*";
      }
      
      short type_id() { return 8; }
      virtual bool passable() { return true; }
      virtual std::string description() { return "ice"; }
  };
}
#endif
