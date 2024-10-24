#ifndef MAP_H
#define MAP_H

#include <vector>
#include "MapComponent.h"

using namespace std;
class Map : public MapComponent
{
	
private:
	vector<vector<MapComponent*>> tiles;

public:
	Map(int id);

	vector<MapComponent *> components;

	bool add(MapComponent *component);

	bool remove(MapComponent *component);

	void getComponent(int id);
};

#endif
