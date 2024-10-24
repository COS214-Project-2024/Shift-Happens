#ifndef MAPCOMPONENT_H
#define MAPCOMPONENT_H

#include <string>

using namespace std;
class MapComponent
{

private:
	int id;

public:
	MapComponent(int id);
	virtual bool add(MapComponent *component) = 0;
	virtual bool remove(MapComponent *component) = 0;
	virtual void getComponent(int id) = 0;
	virtual ~MapComponent();
};

#endif
