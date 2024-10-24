#ifndef CITIZEN_H
#define CITIZEN_H

namespace Building_State {
	class Citizen : Building_State::CitizenObserver {

	private:
		Economy* economy;
		Infrastructural* infrastructure;
		Government* government;
	};
}

#endif
