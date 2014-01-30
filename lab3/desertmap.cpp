#include "treetile.h"
#include "icetile.h"
#include "rocktile.h"
#include "food.h"
#include "grass_tile.h"
#include "button.h"
#include "treemap.h"
#include "victory.h"
#include "terry.h"
#include "desertmap.h"

using namespace lab3;

Desertmap::Desertmap(){
	load_terrain();
	set_map_info("The desert is full of dangerous rocks. Make sure you don't fall on them.");
}

void Desertmap::load_terrain(){
	for (int i = 1; i <= height; i++) {
    add_object_to_map( new RockTile(i,1));
    add_object_to_map( new RockTile(i, length) );
  }
  for (int i = 1; i <= length; i++) {
    add_object_to_map( new RockTile(1, i));
    add_object_to_map( new RockTile(height, i) );
  }
  add_object_to_map( new RockTile(5, 20) );
  add_object_to_map( new RockTile(5, 22) );
  add_object_to_map( new RockTile(6, 19) );
  add_object_to_map( new GrassTile(10,45) );
  add_object_to_map( new GrassTile(10,47) );
  add_object_to_map( new Victory(16,16) );
}