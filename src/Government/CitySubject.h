#ifndef CITYSUBJECT_H
#define CITYSUBJECT_H

namespace Building_State {
	class CitySubject {

	private:
		ClientObserver* observerList;

	public:
		void notify();
	};
}

#endif
