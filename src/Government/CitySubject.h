#ifndef CITYSUBJECT_H
#define CITYSUBJECT_H

#include "../citizens/CitizenObserver.h"
#include <vector>
#include <memory>

	class CitySubject {

	private:
		std::vector<std::shared_ptr<CitizenObserver>> observerList;

	public:
		void attach(std::shared_ptr<CitizenObserver> newObserver);
		void detach(std::shared_ptr<CitizenObserver> ObserverToRemove);
		void notify();
	};

#endif
