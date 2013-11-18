#include "player.h"
#include "object.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace lab3;

Player::Player() : Object() {
}

Player::Player(int x, int y) : Object(x, y) {
  hp = 85;
  hunger = 6;
}

std::string Player::symbol() {
  return "X";
}

void Player::move_down()  { x++; }
void Player::move_right() { y++; }
void Player::move_left()  { y--; }

void Player::get_player_stats(int & hp, int & hunger, int & weight) {
  hp = this->hp;
  hunger = this->hunger;
  weight = this->weight;
}

bool Player::add_to_inventory(Object * o) {
  inventory.push_back(o);
}

int Player::get_weight() {
  return inventory.size();
}

bool Player::drop_object(Object * o) {
  for (std::vector<Object *>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
    if (o == (*it)) {
      inventory.erase(it);
      return true;
    }
  }  
  return false;
}
