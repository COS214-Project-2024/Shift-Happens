#ifndef MAP_H
#define MAP_H

#include <vector>
#include "MapComponent.h"

using namespace std;
namespace Building_State {
	class Map : Building_State::MapComponent {

	public:
		vector<Building_State::MapComponent*> components;

		bool add(Building_State::MapComponent* component);

		bool remove(Building_State::MapComponent* component);

		void getComponent(int id);
	};
}

#endif
