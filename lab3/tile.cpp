#include "tile.h"
#include "object.h"
#include <string>

using namespace lab3;

Tile::Tile() : Object() {
}

Tile::Tile(int x, int y) : Object(x,y) {
}

std::string Tile::symbol() {
  return "O";
}

short Tile::type_id() {
  return 1;
}

bool Tile::passable() {
  return false;
}
