#include <ncurses.h>
#include <vector>
#include "map.h"
#include "tile.h"
#include "tree.h"
#include "player.h"

lab3::Map::Map() : objects( std::vector<lab3::Object>() ) {
  load_terrain();
}

void lab3::Map::add_player() {
  Player p(10,10);
  objects.push_back(p);
}

void lab3::Map::print_map() {
  erase();
  // mvprintw(p.getX(), p.getY(), "X");
  for(std::vector<Object>::iterator it = objects.begin(); it != objects.end(); ++it) {
    mvprintw(it->getX(), it->getY(), "%C", it->sym);
  }
  
  refresh();
}

void lab3::Map::load_terrain() {
  for (int i = 1; i < 30; i++) {
    objects.push_back( Tile(1,i) );
    objects.push_back( Tile(i,1) );
    objects.push_back( Tile(i,30) );
    objects.push_back( Tile(30,i) );
  }
}


