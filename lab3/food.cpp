#include "food.h"
#include "inventorable.h"
#include <string>

using namespace lab3;

Food::Food() : Inventorable() {
}

Food::Food(int x, int y) : Inventorable(x,y) {
  hunger = -3;
}

std::string Food::symbol() {
  return "F";
}

short Food::type_id() {
  return 5;
}

std::string Food::description() {
  return "Food";
}

Object * Food::perform_action() {
  return this;
};
