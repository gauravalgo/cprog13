#ifndef DESMAP_H
#define DESMAP_H

#include "map.h"
namespace lab3{
	class Desertmap : public Map{
	public:
		Desertmap();
		~Desertmap();
		virtual void load_terrain();
	};
}
#endif