#ifndef TREEMAP_H
#define TREEMAP_H

#include "object.h"
#include "character.h"
#include <vector>
#include <string>
#include "tile.h"
#include "player.h"
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