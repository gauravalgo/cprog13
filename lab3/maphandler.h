#ifndef MAPH_H
#define MAPH_H

#include "map.h"
#include <vector>

namespace lab3{
	class Maphandler{
		private:
			std::vector<Map *> maps;
			Player * p;
		public:
			int current_map = 0;
			Maphandler();
			~Maphandler();
			void add_maps();
			Map & get_map();
			void change_map(int);
			void remove_player(Map & m);
	};
}
#endif
