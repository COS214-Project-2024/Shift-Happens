#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include "IndustrialBuilding.h"
#include "Materials.h"
	class Warehouse : public IndustrialBuilding {

	private:
		Materials* materials;
	};

#endif
