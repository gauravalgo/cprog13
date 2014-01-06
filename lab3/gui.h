#ifndef GUI_H
#define GUI_H
#include <ncurses.h>
#include <string>
#include <vector>
#include "object.h"
#include "map.h"

namespace lab3 {
	class Gui {
		private:
			WINDOW* tile_info_window;
			WINDOW* info_window;
			WINDOW* map_window;
			WINDOW* inventory_window;
		public:
			Gui();
			void create_windows();
			void print_tile_info(std::string& text);
			void print_info(std::vector<std::string>& messages, int & hp, int & hunger, int & weight);
			void print_map(std::vector<Object *>& objects);
			void print_object(WINDOW * win, Object * o);
			void display_help(void);
			Object * display_inventory( int & selected, std::vector<Object *> & inventory);
	};
}
#endif