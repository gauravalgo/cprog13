#include <ncurses.h>
#include <map>
#include "map.h"
#include <cstring>
#include "player.h"
#include <iostream>
#include "object.h"
#include <vector>
#include "gui.h"
#include "icemap.h"
#include "treemap.h"

typedef void (*MenuActionPtrType) ( void );
typedef std::map<char, MenuActionPtrType> action_map;

int RUNNING = true;
lab3::Map & m = *(new lab3::Map());
std::vector<lab3::Map* > maps;
std::vector<std::string> messages;
lab3::Gui gui;
std::string tile_info_text;

void print_info();

void add_message(std::string text) {
  if (text.empty()) {
    return;
  }
  messages.insert(messages.begin(), text);
  print_info();
}

void move_self_up( void ) {
  tile_info_text = m.player_move_up();
}

void move_self_down( void ) {
  tile_info_text = m.player_move_down();
}

void move_self_right( void ) {
  tile_info_text = m.player_move_right();
}

void move_self_left( void ) {
  tile_info_text = m.player_move_left();
}

void action_do_stuff( void ) {
  add_message(m.player_do_stuff_to_tile());
}

void action_display_inventory( void ) {
  bool DISPLAY_INVENTORY = true;
  int selected = 0;
  while (DISPLAY_INVENTORY) {
    std::vector<lab3::Object *> inventory = m.get_current_player()->inventory;
    lab3::Object * selected_object = gui.display_inventory(selected, inventory);

    char c = getch();
    if (c == 'w') {
      if (selected > 0) {
        selected--;
      }
    }
    if (c == 's' ) {
      if (selected < inventory.size()-1) {
        selected++;
      }
    }

    if (c == 'd') {
      if (inventory.size() == 0) {
        add_message("Cannot drop non-existing object");
      } else {
        m.drop_object_from_inventory(selected_object);
        add_message("Drop object");
      }
    }
    if (c == ' ') {
      m.get_current_player()->drop_object(selected_object);
      lab3::Object * result_object = selected_object->perform_action();
      selected = 0;
      m.get_current_player()->apply_object_to_object(result_object);
      std::string message =  "You " + selected_object->action_description() + " the " + selected_object->description();
      add_message(message);
    }
    if (c == 'q') {
      DISPLAY_INVENTORY = false;
    }
  }
}

void action_display_help( void  ) {
  gui.display_help();
}

void print_info() {
  int a, b, c;
  m.get_current_player()->get_player_stats(a,b,c);
  gui.print_info(messages, a, b, c);
}

void print_map( void ){
  gui.print_map(m.objects);
}

void print_tile_info( void ){
   gui.print_tile_info(tile_info_text);
}

bool show_notification_box(std::string text) {
  WINDOW * win;
  win = newwin(7,30,10,10);
  box(win, 0,0);
	wattron(win,COLOR_PAIR(666));
  mvwprintw(win, 2,2, text.c_str());
  mvwprintw(win, 4,2, "Press 'n' to stay");
  wrefresh(win);
  char c = getch();

  if (c == 'n') {
    return true;
  }
  return false;
}
void action_quit( void ) {
  RUNNING = show_notification_box("Shutting down");
}

void init_ncurses() {
  initscr();
  noecho();
  curs_set(0);
  start_color();
  refresh();
}

int main() {

  // Actions
  action_map actions;

  actions.insert(std::make_pair<char, MenuActionPtrType>('w', &move_self_up));
  actions.insert(std::make_pair<char, MenuActionPtrType>('d', &move_self_right));
  actions.insert(std::make_pair<char, MenuActionPtrType>('s', &move_self_down));
  actions.insert(std::make_pair<char, MenuActionPtrType>('a', &move_self_left));
  actions.insert(std::make_pair<char, MenuActionPtrType>('q', &action_quit));
  actions.insert(std::make_pair<char, MenuActionPtrType>(' ', &action_do_stuff));
  actions.insert(std::make_pair<char, MenuActionPtrType>('i', &action_display_inventory));
  actions.insert(std::make_pair<char, MenuActionPtrType>('?', &action_display_help));

  add_message("Welcome!");
  
  init_ncurses();
  
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
  init_pair(666, COLOR_RED, COLOR_BLACK);   // Warnings etc
  
  // Require colour
  if(has_colors() == FALSE) {	
    endwin();

    printf("Your terminal does not support color\n");
    RUNNING = false;
	}
  tile_info_text = "Here you will see information about what you encounter.";
  int c;
  action_display_help();
  gui.create_windows();
  print_info();
  print_tile_info();
  print_map();
  while(RUNNING) {
  
    c = getch();
    action_map::const_iterator start = actions.find(c);
    if (start != actions.end()){
      ((*start).second) ();
    }
    print_tile_info();
    print_info();
    print_map();
  }
  endwin();
  delete &m;
  return 0;
}
