#ifndef TREEMAP_H
#define TREEMAP_H

#include "map.h"

namespace lab3{
	class Treemap : public Map{
	public: 
		Treemap();
		~Treemap();
		virtual void load_terrain();
	};
}
#endif