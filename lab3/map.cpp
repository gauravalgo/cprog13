#include <vector>
#include "map.h"
#include "tile.h"
#include "treetile.h"
#include "player.h"
#include "rocktile.h"
#include <iostream>
#include <assert.h>
#include "food.h"
#include <ncurses.h>

using namespace lab3;

lab3::Map::Map() {
  load_terrain();
  add_player();
}

lab3::Map::Map(Player * in) {
  load_terrain();
  add_player();
}

Player lab3::Map::add_player() {
  current_player = (Player * ) new Player(10,10);
  objects.push_back(current_player);

  return *current_player;
}


void lab3::Map::load_terrain() {
  for (int i = 1; i < 10; i++) {
    objects.push_back( new TreeTile(1,i) );
    objects.push_back( new TreeTile(i,1) );
    objects.push_back( new Tile(i+1,30) );
    objects.push_back( new RockTile(20,i) );
  }

  objects.push_back( new Food(2,7) );
  objects.push_back( new Food(2,2) );
  objects.push_back( new Food(2,7) );
}

lab3::Player * lab3::Map::get_current_player() {
  return current_player;
}

// Player interactions
void lab3::Map::player_move_up() {
  Player * player = get_current_player();
  int x = player->getX();
  int y = player->getY();

  player_move_to(player, --x, y);
}

void lab3::Map::player_move_down() {
  Player * player = get_current_player();
  int x = player->getX();
  int y = player->getY();

  player_move_to(player, ++x, y);

}

void lab3::Map::player_move_right() {
  Player * player = get_current_player();
  int x = player->getX();
  int y = player->getY();

  player_move_to(player, x, ++y);
}

void lab3::Map::player_move_left() {
  Player * player = get_current_player();
  int x = player->getX();
  int y = player->getY();

  player_move_to(player, x, --y);
}

void lab3::Map::player_move_to(Player * p, int x, int y) {
  if (is_vacant(x,y)) {
    p->set_position(x,y);
  }
}

std::string lab3::Map::player_do_stuff_to_tile() {
  Player * p = get_current_player();
  std::string out = "Found stuff: ";
  bool found_stuff = false;

  for (std::vector<Object *>::iterator it = objects.begin(); it != objects.end(); ++it) {
    if ( (*it)->getX() == p->getX() && (*it)->getY() == p->getY() && (*it)->type_id() != p->type_id()) {
      found_stuff = true;
      out += (*it)->description();
      p->add_to_inventory( (*it) );
      objects.erase( it );
    }
  }
  if (found_stuff) { return out; }
  return "";
}

/* Can the player stand here? */
bool lab3::Map::is_vacant(int x, int y) {
  Object * o = get_object_at(x, y);

  if (o == NULL) {
    return true;
  }
  return o->passable();
}

Object * lab3::Map::get_object_at(int x, int y) {
  for(std::vector<Object *>::iterator it = objects.begin(); it != objects.end(); ++it) {
    if ((*it)->getX() == x && (*it)->getY() == y) {
      return (*it);
    }
  }
  return NULL;
}
