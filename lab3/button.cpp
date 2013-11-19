#include "button.h"
#include "object.h"
#include <string>

using namespace lab3;

std::string Button::description() {
  if (pressed) {
    return "pressed button";
  }
  return "un-pressed button. Wow!";
}

