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
lab3::Map & m = *(new lab3::Treemap());
std::vector<lab3::Map* > maps;
//std::vector<std::string> messages;
lab3::Gui gui(m);
std::string tile_info_text;

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
  gui.add_message(m.player_do_stuff_to_tile());
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
    else if (c == 's' ) {
      if (selected < inventory.size()-1) {
        selected++;
      }
    }

    else if (c == 'd') {
      if (inventory.size() == 0) {
        gui.add_message("Cannot drop non-existing object");
      } else {
        m.drop_object_from_inventory(selected_object);
        gui.add_message("Drop object");
      }
    }
    else if (c == ' ') {
      if (inventory.size() == 0) {
        gui.add_message("Cannot use non-existing object");
      } else {
        m.get_current_player()->drop_object(selected_object);
        lab3::Object * result_object = selected_object->perform_action();
        selected = 0;
        m.get_current_player()->apply_object_to_object(result_object);
        std::string message =  "You " + selected_object->action_description() + " the " + selected_object->description();
        gui.add_message(message);
    }
    }
    else if (c == 'q') {
      DISPLAY_INVENTORY = false;
    }
  }
}

void action_display_help( void  ) {
  gui.display_help();
}

void print_tile_info( void ){
   gui.print_tile_info(tile_info_text);
}

void action_quit( void ) {
  RUNNING = gui.show_notification_box("Shutting down");
}

void change_level( int ){

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

  gui.add_message("Welcome!");

  // Require colour
  if(has_colors() == FALSE) {	
    endwin();

    printf("Your terminal does not support color\n");
    RUNNING = false;
	}

  int level = 0;
  tile_info_text = "Here you will see information about what you encounter.";
  int c;
  action_display_help();
  gui.create_windows();
  gui.print_info();
  print_tile_info();
  gui.print_map();
  while(RUNNING) {
  
    c = getch();
    action_map::const_iterator start = actions.find(c);
    if (start != actions.end()){
      ((*start).second) ();
    }

    // Move player to other world, if needed
    if (m.set_level > 0) {
      //level = m.set_level;
      gui.add_message("change level");
    }

    print_tile_info();
    gui.print_info();
    gui.print_map();
  }
  endwin();
  delete &m;
  return 0;
}
