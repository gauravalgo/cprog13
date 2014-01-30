#include "map.h"
#include "icemap.h"
#include "treemap.h"
#include "desertmap.h"
#include "maphandler.h"
#include <vector>
#include "player.h"
#include "object.h"

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
	maps.push_back(new Desertmap());
}

Map & Maphandler::get_map(){
	Map & m = *(maps.at(current_map));
	return m;
}

void Maphandler::change_map(int mapnumber){
	remove_player(get_map());
	current_map = mapnumber;
	get_map().add_player(p);
}

void Maphandler::remove_player(Map & m){
  for (std::vector<Object *>::iterator it = m.objects.begin(); it != m.objects.end(); ++it) {
   	short id = (*it)->type_id();
   	if (id == 4){
   		m.objects.erase(it);
   		break;
   }
  }
}