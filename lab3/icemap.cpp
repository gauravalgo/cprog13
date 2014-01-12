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
#include "icemap.h"

using namespace lab3;

Icemap::Icemap(){
	load_terrain();
	add_player();
}

void Icemap::load_terrain(){
  for (int i = 1; i <= height; i++) {
  	add_object_to_map( new TreeTile(i,1));
  	add_object_to_map( new TreeTile(i, length) );
  }
  for (int i = 1; i <= length; i++) {
  	add_object_to_map( new TreeTile(1, i));
  	add_object_to_map( new TreeTile(height, i) );
  }
  for (int i = 2; i < height; ++i)
  {
  	for (int k = 2; k < length; ++k)
  	{
  		add_object_to_map( new IceTile(i, k) );
  	}
  }
}
// Player interactions
std::string Icemap::player_move_up() {
  Player * player = get_current_player();
  int x = player->getX();
  int y = player->getY();
  x--;

  return player_move_to(player, --x, y);
}

std::string Icemap::player_move_down() {
  Player * player = get_current_player();
  int x = player->getX();
  int y = player->getY();
  x++;

  return player_move_to(player, ++x, y);
}

std::string Icemap::player_move_right() {
  Player * player = get_current_player();
  int x = player->getX();
  int y = player->getY();
  y++;

  return player_move_to(player, x, ++y);
}

std::string Icemap::player_move_left() {
  Player * player = get_current_player();
  int x = player->getX();
  int y = player->getY();
  y--;

  return player_move_to(player, x, --y);
}