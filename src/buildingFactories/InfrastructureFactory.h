#ifndef INFRASTRUCTUREFACTORY_H
#define INFRASTRUCTUREFACTORY_H

namespace Building_State {
	class InfrastructureFactory : Building_State::BuildingFactory {


	public:
		Building_State::Infrastructure* build(string variant);
	};
}

#endif
