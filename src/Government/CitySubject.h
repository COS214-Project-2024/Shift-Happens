#ifndef CITYSUBJECT_H
#define CITYSUBJECT_H

#include "../citizens/CitizenObserver.h"
#include <vector>

	class CitySubject {

	private:
		std::vector<CitizenObserver*> observerList;

	public:
		void attach(CitizenObserver* newObserver);
		void detach(CitizenObserver* ObserverToRemove);
		void notify();
	};

#endif
