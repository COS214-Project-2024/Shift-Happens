#ifndef CITYSUBJECT_H
#define CITYSUBJECT_H

#include "../citizens/CitizenObserver.h"
#include <vector>
#include <memory>

/**
 * @class CitySubject
 * @brief An abstract subject class observed by citizens in the observer pattern.
 * 
 * CitySubject maintains a list of observers and provides functionality to add, remove, and notify them of state changes.
 */
class CitySubject {

	private:
		/**
		 * @brief A vector of shared pointers to CitizenObservers representing the current observers of this subject.
		 */
		std::vector<std::shared_ptr<CitizenObserver>> observerList;

	public:
		/**
		 * @brief Attaches a new observer to the observer list.
		 * 
		 * @param newObserver A shared pointer to the observer being added.
		 */
		void attach(std::shared_ptr<CitizenObserver> newObserver);

		/**
		 * @brief Removes an existing observer from the observer list.
		 * 
		 * @param ObserverToRemove A shared pointer to the observer to remove.
		 */
		void detach(std::shared_ptr<CitizenObserver> ObserverToRemove);

		/**
		 * @brief Notifies all attached observers of a state change in the subject.
		 */
		void notify();
};

#endif // CITYSUBJECT_H
