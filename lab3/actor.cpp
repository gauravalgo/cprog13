#include "actor.h"

using namespace lab3;

Actor::Actor() : Object() {
}

Actor::Actor(int x, int y) : Object(x,y) {
}

void Actor::get_actor_stats(int & hp, int & hunger, int & weight) {
  hp = this->hp;
  hunger = this->hunger;
  weight = this->weight;
}

bool Actor::add_to_inventory(Object * o) {
  inventory.push_back(o);
}

int Actor::get_weight() {
  return inventory.size();
}

bool Actor::drop_object(Object * o) {
  for (std::vector<Object *>::iterator it = inventory.begin(); it != inventory.end(); ++it) {
    if (o == (*it)) {
      inventory.erase(it);
      return true;
    }
  }  
  return false;
}

