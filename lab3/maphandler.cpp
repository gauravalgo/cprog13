#include "map.h"
#include "icemap.h"
#include "treemap.h"
#include "maphandler.h"
#include <vector>

using namespace lab3;

Maphandler::Maphandler(){
	add_maps();
}

void Maphandler::add_maps(){
	maps.push_back(new Treemap());
	maps.push_back(new Icemap());
}

Map & Maphandler::get_map(){
	Map & m = *(maps.at(current_map));
	return m;
}

void Maphandler::change_map(int mapnumber){
	current_map = mapnumber;
	changed = false;
}
		
bool Maphandler::changed_level(){
	return changed;
}