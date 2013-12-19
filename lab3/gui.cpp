#include "gui.h"
#include <ncurses.h>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>

using namespace lab3;

	Gui::Gui() {
}

void Gui::create_windows(){
	tile_info_window = newwin(3,70,22,0);
	info_window = newwin(10,70,25,0);
}

void Gui::print_tile_info(std::string& text){
  werase(tile_info_window);
  box(tile_info_window,0,0);
  mvwprintw(tile_info_window, 0, 1, "TileInfoWindow");
  mvwprintw(tile_info_window, 1,1, text.c_str());
  wrefresh(tile_info_window);
}

void Gui::print_info(std::vector<std::string>& messages, int & hp, int & hunger, int & weight){
	werase(info_window);
  box(info_window, 0,0);
  mvwprintw(info_window, 0,1, "Logg");
  mvwprintw(info_window, 2,2, "Player HP %d: Hunger: %d, Total weight: %dkg", hp, hunger, weight);
  int i = 0;
  for (std::vector<std::string>::iterator it = messages.begin(); it != messages.end() && i < 4; it++, i++) {
    mvwprintw(info_window, 4+i, 2, (*it).c_str() ) ;
  }
  wrefresh(info_window);
}