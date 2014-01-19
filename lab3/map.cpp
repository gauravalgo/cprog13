#include <vector>
#include "map.h"
#include "tile.h"
#include "treetile.h"
#include "icetile.h"
#include "player.h"
#include "rocktile.h"
#include <iostream>
#include <assert.h>
#include "food.h"
#include "grass_tile.h"
#include "button.h"
#include <ncurses.h>

using namespace lab3;

lab3::Map::Map() {
  //load_terrain();
  //add_player();
}

lab3::Map::~Map() {
  for (std::vector<Object *>::iterator it = objects.begin(); it != objects.end(); ++it) {
    delete (*it);
  }
  std::cout << "Destructor of map" << std::endl;
}

Player lab3::Map::add_player() {
  current_player = (Player * ) new Player(10,10);
  objects.push_back(current_player);

  return *current_player;
}

bool lab3::Map::add_object_to_map(Object * o) {
  objects.push_back(o);
}

void lab3::Map::load_terrain() {
  for (int i = 1; i <= height; i++) {
    add_object_to_map( new TreeTile(i,1));
    add_object_to_map( new TreeTile(i, length) );
  }
  for (int i = 1; i <= length; i++) {
    add_object_to_map( new TreeTile(1, i));
    add_object_to_map( new TreeTile(height, i) );
  }
  add_object_to_map( new IceTile(4,7) );
  add_object_to_map( new Food(2,7) );
  add_object_to_map( new Food(2,2) );
  add_object_to_map( new Food(2,7) );
  add_object_to_map( new GrassTile(3,7) );
  add_object_to_map( new GrassTile(6,11) );
  add_object_to_map( new Button(19,8) );
}

lab3::Player * lab3::Map::get_current_player() {
  return current_player;
}

// Player interactions
std::string lab3::Map::player_move_up() {
  Player * player = get_current_player();
  int x = player->getX();
  int y = player->getY();

  return player_move_to(player, --x, y);
}

std::string lab3::Map::player_move_down() {
  Player * player = get_current_player();
  int x = player->getX();
  int y = player->getY();

  return player_move_to(player, ++x, y);
}

std::string lab3::Map::player_move_right() {
  Player * player = get_current_player();
  int x = player->getX();
  int y = player->getY();

  return player_move_to(player, x, ++y);
}

std::string lab3::Map::player_move_left() {
  Player * player = get_current_player();
  int x = player->getX();
  int y = player->getY();

  return player_move_to(player, x, --y);
}

std::string lab3::Map::player_move_to(Player * p, int x, int y) {
  if (is_vacant(x,y)) {
    std::string out = get_message_from_position(x,y);
    p->set_position(x,y);
    if (out.empty()) {
      return "";
    }
    return "You see: " + out;
  }
  return "You can't go there!";
}

std::string lab3::Map::get_message_from_position(int x, int y) {
  Object * o = get_object_at(x,y);
  if (o != NULL)
    return o->description();
  return "";
}

std::string lab3::Map::player_do_stuff_to_tile() {
  Player * p = get_current_player();
  std::string out;
  bool found_stuff = false;

  for (std::vector<Object *>::iterator it = objects.begin(); it != objects.end(); ++it) {
    if ( (*it)->getX() == p->getX() && (*it)->getY() == p->getY() && (*it)->type_id() != p->type_id()) {
      if ((*it)->inventorable()) {
        found_stuff = true;
        out += "Found: ";
        out += ((*it)->description().c_str() );
        out += ". ";
        p->add_to_inventory( (*it) );
        objects.erase( it );
        return out; // fix for segfault

      } else if ((*it)->actionable()) {
        if ( (*it)->can_do_action() ){
          Object * o = (*it)->perform_action();
          if (o->change_level > 0) {
            set_level = o->change_level;
          } else {
            add_object_to_map(o);
          }
        }
        out += "You " + (*it)->action_description() + " the " + (*it)->description();
      }
    }
  }

  if (found_stuff) { return out; }
  return out;
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

bool lab3::Map::drop_object_from_inventory(Object * o) {
  o->set_position(get_current_player()->getX(), get_current_player()->getY());
  add_object_to_map(o);

  get_current_player()->drop_object(o); 

  return true;
}
