#include "gui.h"
#include <ncurses.h>
#include <cstring>
#include <string>
#include <iostream>

using namespace lab3;

	Gui::Gui() {
	tile_info_window = newwin(3,70,22,0);
}

void Gui::print_tile_info(std::string text){
  werase(tile_info_window);
  box(tile_info_window,0,0);
  mvwprintw(tile_info_window, 0, 1, "TileInfoWindow");
  mvwprintw(tile_info_window, 1,1, text.c_str());
  wrefresh(tile_info_window);

}
