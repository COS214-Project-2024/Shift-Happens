#ifndef MANUFACTURER_H
#define MANUFACTURER_H


namespace Building_State {
	class Manufacturer : Building_State::IndustrialBuilding {

	private:
		Building_State::Materials* materials;
	};
}

#endif
