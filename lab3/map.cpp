#include <ncurses.h>
#include <vector>
#include "map.h"
#include "tile.h"
#include "treetile.h"
#include "player.h"
#include "rocktile.h"
#include <iostream>
#include <assert.h>
#include <memory.h> //shared ptr

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
  objects.push_back(new Player(10,10));
  current_player = (Player * ) objects.back();

  return *current_player;
}

void lab3::Map::print_map() {
  erase();
  
  for(std::vector<Object *>::iterator it = objects.begin(); it != objects.end(); ++it) {
    const char * sym = (*it)->symbol().c_str();
    mvprintw((*it)->getX(), (*it)->getY(), sym);
  }

  refresh();
}

void lab3::Map::load_terrain() {
  for (int i = 1; i < 10; i++) {
    objects.push_back( new TreeTile(1,i) );
    objects.push_back( new TreeTile(i,1) );
    objects.push_back( new Tile(i+1,30) );
    objects.push_back( new RockTile(20,i) );
  }
}

lab3::Player * lab3::Map::get_current_player() {
  return current_player;
}

