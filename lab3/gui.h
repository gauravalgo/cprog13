#ifndef GUI_H
#define GUI_H
#include <ncurses.h>
#include <string>
#include <vector>

namespace lab3 {
	class Gui {
		private:
			WINDOW* tile_info_window;
			WINDOW* info_window;
		public:
			Gui();
			void create_windows();
			void print_tile_info(std::string& text);
			void print_info(std::vector<std::string>& messages, int & hp, int & hunger, int & weight);
	};
}
#endif