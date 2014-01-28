#ifndef MAPH_H
#define MAPH_H

#include "map.h"
#include "icemap.h"
#include "treemap.h"
#include <vector>

namespace lab3{
	class Maphandler{
		private:
			std::vector<Map *> maps;
			int current_map = 0;
			bool changed = false;
		public:
			Maphandler();
			void add_maps();
			Map & get_map();
			void change_map(int);
			bool changed_level();
	};
}
#endif