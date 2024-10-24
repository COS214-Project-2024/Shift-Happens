#ifndef UTILITYBUILDING_H
#define UTILITYBUILDING_H

namespace Building_State {
	class UtilityBuilding : Building_State::Building {

	public:
		int runningCostPerHour;

		int getRunningCostPerHour();

		void setRunningCostPerHour(int runningCostPerHour);
	};
}

#endif
