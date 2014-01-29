#include "gui.h"
#include <ncurses.h>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include "object.h"
#include "map.h"
#include "treemap.h"

using namespace lab3;

  Gui::Gui(lab3::Map & m):map(m) {
    init_ncurses();
}

void Gui::init_ncurses() {
  initscr();
  noecho();
  curs_set(0);
  start_color();
  refresh();
  // Set all color pairs, uses type_id from objects
  // The pair 0 is reserved. // init_pair(0, COLOR_WHITE, COLOR_BLACK);   // Object, should be standrad out color
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);  // Tile
  init_pair(2, COLOR_BLACK, COLOR_RED);     // RockTile
  init_pair(3, COLOR_WHITE, COLOR_GREEN);   // TreeTile
  init_pair(4, COLOR_BLUE, COLOR_WHITE);    // The dude
  init_pair(5, COLOR_GREEN, COLOR_YELLOW);  // Food
  init_pair(6, COLOR_WHITE, COLOR_GREEN);   // Grass
  init_pair(7, COLOR_RED, COLOR_WHITE);     // Button
  init_pair(8, COLOR_WHITE, COLOR_WHITE);   // Ice
  init_pair(9, COLOR_WHITE, COLOR_RED);     // Teleporter
  init_pair(12, COLOR_YELLOW, COLOR_RED);   // Characters
  init_pair(666, COLOR_RED, COLOR_BLACK);   // Warnings etc
  
}

void Gui::update_map(Map & new_map){
  map = new_map;
}
void Gui::create_windows(){
	tile_info_window = newwin(3,70,22,0);
	info_window = newwin(10,70,25,0);
	map_window = newwin(22,70,0,0);
	inventory_window = newwin(20,30,10,20);
}

void Gui::print_tile_info(std::string& text){
  werase(tile_info_window);
  box(tile_info_window,0,0);
  mvwprintw(tile_info_window, 0, 1, "TileInfoWindow");
  mvwprintw(tile_info_window, 1,1, text.c_str());
  wrefresh(tile_info_window);
}

void Gui::print_info(){
  int hp, hunger, weight;
  map.get_current_player()->get_player_stats(hp, hunger, weight);
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

void Gui::print_map(){
  std::vector<Object *>& objects = map.objects;
	werase(map_window);
  box(map_window, 0,0); 
  for(std::vector<Object *>::iterator it = objects.begin(); it != objects.end(); ++it) {
    Gui::print_object( map_window, (*it) );
  }

  wrefresh(map_window);
}

void Gui::print_object(WINDOW * win, Object * o) {
    const char * sym = o->symbol().c_str();
    short id = o->type_id();
    wattron(win, COLOR_PAIR(id));
    mvwprintw( win, o->getX(), o->getY(), sym);
    wattroff(win, COLOR_PAIR(id));
}

void Gui::display_help( void ){
  WINDOW * help_window;
  help_window = newwin(24,50,10,10);
  box(help_window, 0,0);
  mvwprintw(help_window, 0, 1, "Help");
  mvwprintw(help_window, 2, 2, "Jag get detta spel 4 av 5 toasters. /Anna");

  mvwprintw(help_window, 4,2, "Move-keys: w,a,s,d");
  mvwprintw(help_window, 5,2, "Pick up objects: space-key");
  mvwprintw(help_window, 6,2, "See your inventory: i");
  mvwprintw(help_window, 7,2, "View help: ?");

  mvwprintw(help_window, 20,2, "Press anykey to close this box");

  wrefresh(help_window);
  getch();
}

Object * Gui::display_inventory( int & selected, std::vector<Object *> & inventory) {

    werase(inventory_window);
    box(inventory_window,0,0);
		mvwprintw(inventory_window, 0, 1, "Inventory: %d items.", inventory.size());
    Object * selected_object;

    int i = 0;
    for (std::vector<Object *>::iterator it = inventory.begin(); it != inventory.end(); ++it, ++i) {
      if ( i == selected ) {
        mvwprintw(inventory_window, 2+i,2,"[X]");
        selected_object = (*it);
      } else {
        mvwprintw(inventory_window, 2+i,2,"[ ]");
      }
      wattron(inventory_window, COLOR_PAIR( (*it)->type_id()) );
      mvwprintw(inventory_window, 2+i,6,(*it)->symbol().c_str());
      wattroff(inventory_window, COLOR_PAIR( (*it)->type_id() ));
      mvwprintw(inventory_window, 2+i, 8, (*it)->description().c_str());
    }
    
    mvwprintw(inventory_window, 14, 2, "Press space-char to use");
    mvwprintw(inventory_window, 16, 2, "press d to drop the object");
    mvwprintw(inventory_window, 18, 2, "Press q to close");
    wrefresh(inventory_window);
    return selected_object;
}

bool Gui::show_notification_box(std::string text) {
  WINDOW * win;
  win = newwin(7,45,10,10);
  box(win, 0,0);
  mvwprintw(win, 1,1, text.c_str());
  mvwprintw(win, 5,1, "Press 'n' to stay");
  wrefresh(win);
  char c = getch();

  if (c == 'n') {
    return true;
  }
  return false;
}
void Gui::add_message(std::string text) {
  if (text.empty()) {
    return;
  }
  messages.insert(messages.begin(), text);
  print_info();
  wrefresh(info_window);
}
