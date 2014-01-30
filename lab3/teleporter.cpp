#include "tile.h"
#include "teleporter.h"

using namespace lab3;

Object * Teleporter::perform_action() {
	change_level += 1;
	return this;
};
