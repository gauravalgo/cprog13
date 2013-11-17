#include "food.h"
#include "object.h"
#include <string>

using namespace lab3;

Food::Food() : Object() {
}

Food::Food(int x, int y) : Object(x,y) {
}

std::string Food::symbol() {
  return "F";
}

short Food::type_id() {
  return 5;
}

std::string Food::description() {
  return "Foods ";
}
