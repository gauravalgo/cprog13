#ifndef GUI_H
#define GUI_H
#include <ncurses.h>
#include <string>

namespace lab3 {
	class Gui {
		private:
			WINDOW* tile_info_window;
		public:
			Gui();
			void print_tile_info(std::string text);
	};
}

#endif