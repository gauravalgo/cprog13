#include <ncurses.h>
#include <vector>
#include "map.h"
#include "tile.h"
#include "tree.h"
#include "player.h"

using namespace lab3;

lab3::Map::Map() : objects( std::vector<lab3::Object>() ) {
  load_terrain();
  add_player();
}

void lab3::Map::add_player() {
  Player p = Player(10,10);
  current_player = p;
  objects.push_back(p);
}

void lab3::Map::print_map() {
  erase();
  
  for(std::vector<Object>::iterator it = objects.begin(); it != objects.end(); ++it) {
    const char * sym = it->symbol().c_str();
    mvprintw(it->getX(),it->getY(), sym);
    // mvprintw(it->getX(), it->getY(), "T");
  }
  // mvprintw(get_current_player().getX(), get_current_player().getY(), "X");
  
  refresh();
}

void lab3::Map::load_terrain() {
  for (int i = 1; i < 30; i++) {
    objects.push_back( Tile(1,i) );
    objects.push_back( Tile(i,1) );
    objects.push_back( Tile(i+1,30) );
    objects.push_back( Tile(30,i) );
  }
}

lab3::Player * lab3::Map::get_current_player() {
  return current_player;
}

