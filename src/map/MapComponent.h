#ifndef MAPCOMPONENT_H
#define MAPCOMPONENT_H

#include <string>

using namespace std;
namespace Building_State {
	class MapComponent {

	private:
		int id;

	public:
		virtual bool add(Building_State::MapComponent* component) = 0;

		virtual bool remove(Building_State::MapComponent* component) = 0;

		virtual void getComponent(int id) = 0;
	};
}

#endif
