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
}

std::string Player::symbol() {
  return "X";
}

void Player::move_down() { x++; }
void Player::move_right() { y++; }
void Player::move_left() { y--; }

void Player::get_player_stats(int & hp, int & hunger, int & weight) {
  hp = 100;
  hunger = 6;
  weight = get_weight();
}

bool Player::add_to_inventory(Object * o) {
  inventory.push_back(o);
}

int Player::get_weight() {
  return inventory.size();
}

Object * Player::drop_object(int i) {
  int j = 0;
  for (std::vector<Object *>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
    if (i == j) {
      Object * o = (*it);
      inventory.erase(it);
      return o;
    }
    j++;
  }  
  return NULL;
}
// Object * Player::use_object_from_inventory(int i){
//   std::vector<Object *>::iterator it = inventory.begin();
//   std::advance(it, i);
//   if ( (*it)->can_do_action()) {
//     Object * outputObject = (*it)->perform_action();
//     inventory.erase(it);
//     return outputObject;
//   }
//   return NULL;
// }

