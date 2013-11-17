#include <ncurses.h>
#include <map>
#include "map.h"
#include <cstring>
#include "player.h"
#include <iostream>
#include "object.h"
#include <vector>

typedef void (*MenuActionPtrType) ( void );
typedef std::map<char, MenuActionPtrType> action_map;

int RUNNING = true;

lab3::Map m;

void move_self_up( void ) {
  m.player_move_up();
}

void move_self_down( void ) {
  m.player_move_down();
}

void move_self_right( void ) {
  m.player_move_right();
}

void move_self_left( void ) {
  m.player_move_left();
}

void action_do_stuff( void ) {
  m.player_do_stuff_to_tile();
}

void action_display_help( void  ) {
  WINDOW * help_window;
  help_window = newwin(24,40,10,10);
  box(help_window, 0,0);
  mvwprintw(help_window, 0, 1, "Help");

  mvwprintw(help_window, 2,2, "Move-keys: w,a,s,d");
  mvwprintw(help_window, 4,2, "Pick up objects: space-key");
  mvwprintw(help_window, 6,2, "View help: ?");


  mvwprintw(help_window, 20,2, "Press anykey to close this box");

  wrefresh(help_window);
  getch();

}

void action_quit( void ) {
	attron(COLOR_PAIR(666));
  printw("Shuttin down");
  getch();

  RUNNING = false;
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
  int top_left_corner;
  werase(win);
  box(win, 0,0); 
  for(std::vector<lab3::Object *>::iterator it = m.objects.begin(); it != m.objects.end(); ++it) {
    print_object( win, (*it) );
  }

  wrefresh(win);
}

void print_info(WINDOW * win) {
  werase(win);
  box(win, 0,0);

  int a, b, c;
  m.get_current_player()->get_player_stats(a,b,c);
  mvwprintw(win, 2,2, "Player HP %d: Hunger: %d, Total weight: %dkg", a, b,c);
  wrefresh(win);
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
  actions.insert(std::make_pair<char, MenuActionPtrType>('?', &action_display_help));

  WINDOW* game_window;
  WINDOW* info_window;
  
  init_ncurses();
  
  // Set all color paris, uses type_id from objects
  // init_pair(0, COLOR_WHITE, COLOR_BLACK);   // Object, should be standrad out color
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);  // Tile
  init_pair(2, COLOR_BLACK, COLOR_RED);     // RockTile
  init_pair(3, COLOR_WHITE, COLOR_GREEN);   // TreeTile
  init_pair(4, COLOR_BLUE, COLOR_WHITE);    // The dude
  init_pair(5, COLOR_GREEN, COLOR_YELLOW);  // Food
  init_pair(666, COLOR_RED, COLOR_BLACK);   // Warnings etc
  
  game_window = newwin(40,70,0,0);
  box(game_window, 0,0);
  mvwprintw(game_window, 0, 1, "GameWindow");
  
  info_window = newwin(10,70,40,0);
  box(info_window, 0,0);
  mvwprintw(info_window, 0, 1, "Stats");
  // wrefresh(info_window);

  // Require colour
  if(has_colors() == FALSE) {	
    endwin();

    printf("Your terminal does not support color\n");
    RUNNING = false;
	}

  int c;
  action_display_help();
  print_map(game_window);
  print_info(info_window);

  while(RUNNING) {
  
    c = getch();
    action_map::const_iterator start = actions.find(c);
    if (start != actions.end()){
      ((*start).second) ();
    }

    print_info(info_window);
    print_map(game_window);
  }
  endwin();
  return 0;
}
