#ifndef POWERPLANT_H
#define POWERPLANT_H

namespace Building_State {
	class PowerPlant : Building_State::UtilityBuilding {

	public:
		int electricityProduction;

		void getElectricityProduction();

		void setElectricityProduction(int electricityProduction);
	};
}

#endif
