#include "player.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace lab3;

Player::Player() : Character() {
}

Player::Player(int x, int y) : Character(x, y) {
  hp = 85;
  hunger = 6;
}

std::string Player::symbol() {
  return "X";
}
