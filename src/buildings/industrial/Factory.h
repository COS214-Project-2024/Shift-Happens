#ifndef FACTORY_H
#define FACTORY_H

namespace Building_State {
	class Factory : Building_State::IndustrialBuilding {

	private:
		Building_State::Materials* materials;
	};
}

#endif
