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
			std::vector<std::string> messages;
			Map & map;

		public:
			Gui(Map & m);
			void init_ncurses();
			void update_map(Map & new_map);
			void create_windows();
			void print_tile_info(std::string& text);
			void print_info();
			void print_map();
			void print_object(WINDOW * win, Object * o);
			void display_help(void);
			Object * display_inventory( int & selected, std::vector<Object *> & inventory);
			bool show_notification_box(std::string text);
			void add_message(std::string text);
	};
}
#endif