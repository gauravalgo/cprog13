#ifndef ICEMAP_H
#define ICEMAP_H

#include "object.h"
#include "character.h"
#include <vector>
#include <string>
#include "tile.h"
#include "player.h"
#include "map.h"

namespace lab3{
	class Icemap : public Map{
	public: 
		Icemap();
		~Icemap();
		virtual void load_terrain();
	};
}
#endif