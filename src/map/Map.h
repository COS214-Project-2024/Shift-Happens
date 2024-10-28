#ifndef MAP_H
#define MAP_H

#include <vector>
#include <memory>
#include "MapComponent.h"

using namespace std;

class Map : public MapComponent
{
	
private:
	//vector<vector<MapComponent*>> tiles;
	vector<vector<shared_ptr<MapComponent>>> tiles;


public:
	Map(int id);
	std::vector<std::shared_ptr<MapComponent>> components;
	
	bool add(MapComponent *component);

	bool remove(MapComponent *component);

	void getComponent(int id);

	void render();
};

#endif
