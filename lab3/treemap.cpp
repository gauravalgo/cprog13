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
#include "treemap.h"

using namespace lab3;

Treemap::Treemap(){
	load_terrain();
	//add_player();
  set_map_info("Welcome to the green fields of france. Some say a mysterious button can be found here.");

}

void Treemap::load_terrain(){
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
