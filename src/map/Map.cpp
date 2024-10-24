#include "Map.h"

Map::Map(int id) : MapComponent(id) {
	//standard map size is 25x25
	for (size_t i = 0; i < 25; i++)
	{
		vector<MapComponent*> row;
		for (size_t j = 0; j < 25; j++)
		{
			row.push_back(nullptr);
		}
		tiles.push_back(row);
	}
}

bool Map::add(MapComponent* component) {
	// TODO - implement Map::add
	throw "Not yet implemented";
}

bool Map::remove(MapComponent* component) {
	// TODO - implement Map::remove
	throw "Not yet implemented";
}

void Map::getComponent(int id) {
	// TODO - implement Map::getComponent
	throw "Not yet implemented";
}
