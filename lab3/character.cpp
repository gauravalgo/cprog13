#include "character.h"
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include "object.h"

using namespace lab3;

bool Character::add_to_inventory(Object * o) {
  inventory.push_back(o);
}

int Character::get_weight() {
  return inventory.size();
}

Character::~Character() {
  for (std::vector<Object *>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
    delete (*it);
  }
}

void Character::get_player_stats(int & hp, int & hunger, int & weight) {
  hp = this->hp;
  hunger = this->hunger;
  weight = this->weight;
}

bool Character::drop_object(Object * o) {
  for (std::vector<Object *>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
    if (o == (*it)) {
      inventory.erase(it);
      return true;
    }
  }  
  return false;
}

std::string Character::symbol() { return "c"; };
