#include "object.h"

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

