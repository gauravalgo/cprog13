#include "player.h"
#include "object.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "actor.h"

using namespace lab3;

Player::Player() : Actor() {
}

Player::Player(int x, int y) : Actor(x, y) {
  hp = 85;
  hunger = 6;
}

