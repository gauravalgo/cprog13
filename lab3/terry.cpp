#include "terry.h"
#include "character.h"
#include <string>
#include "food.h"
#include <iostream>
#include "teleporter.h"

using namespace lab3;

Terry::Terry(int x, int y) : Character(x, y) {
  hp = 100;
}

Object * Terry::perform_action() {
  if (unused) {
    unused = false;
    return new Teleporter(2,2);
  }
}

Object * Terry::tick() {
  if (count == 3) {
    x = x + 1;
  }
  count++;
  if (count > 10) {
    x = x-1;
    count = 0;
  }
}
