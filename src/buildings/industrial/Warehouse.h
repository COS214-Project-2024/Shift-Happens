#ifndef WAREHOUSE_H
#define WAREHOUSE_H

namespace Building_State {
	class Warehouse : Building_State::IndustrialBuilding {

	private:
		Building_State::Materials* materials;
	};
}

#endif
