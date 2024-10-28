#include "Map.h"
#include <iostream>
Map::Map(int id) : MapComponent(id) {
	throw "Map::Map(int id) not implemented";
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


void Map::render() {
	//genereate a 25x25 map grid
	//if a tile is empty, print a space
	
	/*example 
	
	-------------------------
	|  |  |  |  |  |  |  |  |
	|  |  |  |  |  |  |  |  |
	|  |  |  |  |  |  |  |  |
	|  |  |  |  |  |  |  |  |
	|  |  |  |  |  |  |  |  |
	|  |  |  |  |  |  |  |  |
	|  |  |  |  |  |  |  |  |
	|  |  |  |  |  |  |  |  |
	-------------------------
	*/
	for (size_t i = 0; i < 25; i++)
	{
		for (size_t j = 0; j < 25; j++)
		{
			if (tiles[i][j] == nullptr)
			{
				std::cout << "|  ";
			}
			else
			{
				std::cout << "|X ";
			}
		}
		std::cout << "|" << std::endl;
	}
}