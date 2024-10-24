#ifndef STORE_H
#define STORE_H

namespace Building_State {
	class Store : Building_State::CommercialBuilding {

	private:
		Building_State::Materials* materials;
	};
}

#endif
