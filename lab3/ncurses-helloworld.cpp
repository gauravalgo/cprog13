#include <ncurses.h>
#include <map>
#include "map.h"
#include <cstring>
#include "player.h"
#include <iostream>

typedef void (*MenuActionPtrType) ( void );
typedef std::map<char, MenuActionPtrType> action_map;

int RUNNING = true;

lab3::Map m;

void move_self_up( void ) {
  m.player_move_up();
}
void move_self_down( void ) {
  m.player_move_down();
  // m.get_current_player()->move_down();
}

void move_self_right( void ) {
  m.player_move_right();
  // m.get_current_player()->move_right();
}

void move_self_left( void ) {
  m.player_move_left();
  // m.get_current_player()->move_left();
}

void action_quit( void ) {
  init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
  printw("Shuttin down");
  getch();

  RUNNING = false;
}

void init_ncurses() {
  initscr();
  noecho();
  curs_set(0);
  start_color();
}

int main() {
  action_map actions;

  actions.insert(std::make_pair<char, MenuActionPtrType>('w', &move_self_up));
  actions.insert(std::make_pair<char, MenuActionPtrType>('d', &move_self_right));
  actions.insert(std::make_pair<char, MenuActionPtrType>('s', &move_self_down));
  actions.insert(std::make_pair<char, MenuActionPtrType>('a', &move_self_left));
  actions.insert(std::make_pair<char, MenuActionPtrType>('q', &action_quit));

  init_ncurses();

  // Require colour
  if(has_colors() == FALSE) {	
    endwin();

    printf("Your terminal does not support color\n");
    RUNNING = false;
	}

  // Set all color paris, uses type_id from objects
  init_pair(0, COLOR_WHITE, COLOR_BLACK);   // Object, should be standrad out color
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);  // Tile
  init_pair(2, COLOR_BLACK, COLOR_RED);     // RockTile
  init_pair(3, COLOR_WHITE, COLOR_GREEN);   // TreeTile
  init_pair(4, COLOR_BLUE, COLOR_WHITE);    // The dude

  int c;
  m.print_map();

  while(RUNNING) {
  
    mvprintw(35,5, "%d %d", m.get_current_player()->getX(), m.objects.back()->getX() );
    
    c = getch();
    action_map::const_iterator start = actions.find(c);
    if (start != actions.end()){
      ((*start).second) ();
    }

    m.print_map();
  }
  endwin();
  return 0;
}
