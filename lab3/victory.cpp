#include "victory.h"
#include "inventorable.h"
#include <string>

using namespace lab3;

Victory::Victory() : Inventorable() {
}

Victory::Victory(int x, int y) : Inventorable(x, y) {
}

Object * Victory::perform_action() {
  return this;
}
