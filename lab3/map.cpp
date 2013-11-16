#include <ncurses.h>
#include <vector>
#include "map.h"
#include "tile.h"
#include "tree.h"
#include "player.h"
#include <iostream>
#include <assert.h>
#include <memory.h> //shared ptr

using namespace lab3;

lab3::Map::Map() {
  objects = {};
  load_terrain();
  add_player();
}

lab3::Map::Map(Player * in) {
  objects = {};
  load_terrain();
  add_player();
}

Player lab3::Map::add_player() {
  // ligger pa heapen
  // Player p(10,10);
  // Player p = *(new Player(10,10));
  objects.push_back(new Player(10,10));
  current_player = (Player * ) objects.back();
  // current_player = in;
  
  // assert(in->getX() == objects.back().getX());
  return *current_player;
}

void lab3::Map::print_map() {
  erase();
  
  for(std::vector<Object *>::iterator it = objects.begin(); it != objects.end(); ++it) {
    const char * sym = (*it)->symbol().c_str();
    mvprintw((*it)->getX(), (*it)->getY(), sym);
    // std::cout << "-" << it->getX();
    // mvprintw(it->getX(), it->getY(), "T");
  }
  
  // const char * sym = get_current_player()->symbol().c_str();
  // mvprintw(get_current_player()->getX(), get_current_player()->getY(), sym);
  // std::cout << std::endl;
  refresh();
}

void lab3::Map::load_terrain() {
  for (int i = 1; i < 10; i++) {
    objects.push_back( new Tile(1,i) );
    objects.push_back( new Tile(i,1) );
    // objects.push_back( Tile(i+1,30) );
    // objects.push_back( Tile(30,i) );
  }
}

lab3::Player * lab3::Map::get_current_player() {
  return current_player;
  // return &objects.back();
}

