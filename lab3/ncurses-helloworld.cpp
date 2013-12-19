#include <ncurses.h>
#include <map>
#include "map.h"
#include <cstring>
#include "player.h"
#include <iostream>
#include "object.h"
#include <vector>
#include "gui.h"

typedef void (*MenuActionPtrType) ( void );
typedef std::map<char, MenuActionPtrType> action_map;

int RUNNING = true;

lab3::Map & m = *(new lab3::Map());
std::vector<std::string> messages;
WINDOW* inventory_window;
WINDOW* info_window;
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
    werase(inventory_window);
    box(inventory_window,0,0);

    std::vector<lab3::Object *> inventory = m.get_current_player()->inventory;

    mvwprintw(inventory_window, 0, 1, "Inventory: %d items.", inventory.size());
    lab3::Object * selected_object;

    int i = 0;
    for (std::vector<lab3::Object *>::iterator it = inventory.begin(); it != inventory.end(); ++it, ++i) {
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

void print_object(WINDOW * win, lab3::Object * o) {
    const char * sym = o->symbol().c_str();
    short id = o->type_id();
    wattron(win, COLOR_PAIR(id));
    mvwprintw( win, o->getX(), o->getY(), sym);
    wattroff(win, COLOR_PAIR(id));
}



void print_map(WINDOW * win) {
  werase(win);
  box(win, 0,0); 
  for(std::vector<lab3::Object *>::iterator it = m.objects.begin(); it != m.objects.end(); ++it) {
    print_object( win, (*it) );
  }

  wrefresh(win);
}

void print_info() {
  int a, b, c;
  m.get_current_player()->get_player_stats(a,b,c);
  gui.print_info(messages, a, b, c);
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

  WINDOW* game_window;
  add_message("Welcome!");
  
  init_ncurses();
  
  // Set all color paris, uses type_id from objects
  // The pair 0 is reserved. // init_pair(0, COLOR_WHITE, COLOR_BLACK);   // Object, should be standrad out color
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);  // Tile
  init_pair(2, COLOR_BLACK, COLOR_RED);     // RockTile
  init_pair(3, COLOR_WHITE, COLOR_GREEN);   // TreeTile
  init_pair(4, COLOR_BLUE, COLOR_WHITE);    // The dude
  init_pair(5, COLOR_GREEN, COLOR_YELLOW);  // Food
  init_pair(6, COLOR_WHITE, COLOR_GREEN);   // Grass
  init_pair(7, COLOR_RED, COLOR_WHITE);     // Button
  init_pair(666, COLOR_RED, COLOR_BLACK);   // Warnings etc
  
  game_window = newwin(22,70,0,0);
  box(game_window, 0,0);
  mvwprintw(game_window, 0, 1, "GameWindow");

  
  //info_window = newwin(10,70,25,0);
  inventory_window = newwin(20,30,10,20);

  // Require colour
  if(has_colors() == FALSE) {	
    endwin();

    printf("Your terminal does not support color\n");
    RUNNING = false;
	}
  tile_info_text = "Here you will see information about what you encounter.";
  int c;
  action_display_help();
  print_map(game_window);
  
  gui.create_windows();
  print_info();
  gui.print_tile_info(tile_info_text);
  while(RUNNING) {
  
    c = getch();
    action_map::const_iterator start = actions.find(c);
    if (start != actions.end()){
      ((*start).second) ();
    }
    gui.print_tile_info(tile_info_text);
    print_info();
    print_map(game_window);
  }
  endwin();
  delete &m;
  return 0;
}
