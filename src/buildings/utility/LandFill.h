#ifndef LANDFILL_H
#define LANDFILL_H

namespace Building_State {
	class LandFill : Building_State::UtilityBuilding {

	public:
		int wasteRemovalRate;

		int getWasteRemovalRate();

		void setWasteRemovalRate(int wasteRemovalRate);
	};
}

#endif
