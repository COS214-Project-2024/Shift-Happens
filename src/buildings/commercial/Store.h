#ifndef STORE_H
#define STORE_H
#include "CommercialBuilding.h"
#include "Materials.h"	
class Store : public CommercialBuilding
{

public:
	Store(int id);
	~Store();
private:
	Materials *materials;


};

#endif
