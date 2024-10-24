#ifndef SEWAGEPLANT_H
#define SEWAGEPLANT_H

namespace Building_State {
	class SewagePlant : Building_State::UtilityBuilding {

	public:
		int sewageRemovalRate;

		int getSewageRemovalRate();

		void setSewageRemovalRate(int sewageRemovalRate);
	};
}

#endif
