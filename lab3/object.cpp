#include "object.h"
#include <string>

using namespace lab3;

Object::Object() {
}

Object::Object(int X, int Y) {
  x = X;
  y = Y;
}

int Object::getX() {
  return x;
}

int Object::getY() {
  return y;
}

std::string Object::symbol() {
  return "5";
}

std::string Object::description() {
  return "an object ";
}

short Object::type_id() {
  return 0;
}

void Object::set_position(int x, int y) {
  this->x = x;
  this->y = y;
}
