#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

namespace Building_State {
	class WaterSupply : Building_State::UtilityBuilding {

	public:
		int waterSupply;

		int getWaterSupply();

		void setWaterSupply(int waterSupply);
	};
}

#endif
