#ifndef ECONOMY_H
#define ECONOMY_H

#include "CitySubject.h"
#include "Population.h"

// Concrete subject in observer pattern
// Context in state pattern
/**
 * @class Economy
 * @brief 
 */



class Economy : public CitySubject {
	private:
		std::shared_ptr<Population> PopulationState;

	public:
		void setPopulationState(std::shared_ptr<Population> newState);
		std::shared_ptr<Population> getState();
};


#endif
