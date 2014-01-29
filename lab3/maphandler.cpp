#include "map.h"
#include "icemap.h"
#include "treemap.h"
#include "maphandler.h"
#include <vector>
#include "player.h"

using namespace lab3;

Maphandler::Maphandler(){
	add_maps();
	p = (Player * ) new Player(10,10);
	get_map().add_player(p);

}

Maphandler::~Maphandler(){
	for (std::vector<Map *>::iterator it = maps.begin(); it != maps.end(); ++it) {
    delete (*it);
  }
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
	get_map().remove_player();
	current_map = mapnumber;
	get_map().add_player(p);
	changed = false;
}
		
bool Maphandler::changed_level(){
	return changed;
}