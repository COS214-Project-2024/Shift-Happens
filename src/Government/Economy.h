#ifndef ECONOMY_H
#define ECONOMY_H

#include "CitySubject.h"
#include "Population.h"

// Concrete subject in observer pattern
// Context in state pattern

/**
 * @class Economy
 * @brief Represents the economic state of a city and acts as a concrete subject in the observer pattern.
 * 
 * This class holds a shared pointer to a `Population` state object, allowing 
 * it to observe and manage the population dynamics within the city. 
 * As a subject in the observer pattern, it notifies registered observers 
 * about changes in the economic state.
 */
class Economy : public CitySubject {
private:
    std::shared_ptr<Population> PopulationState; ///< Shared pointer to the current population state.

public:
    /**
     * @brief Sets the current population state.
     * 
     * This method updates the population state to a new state object, 
     * allowing the economy to react to changes in the population.
     * 
     * @param newState A shared pointer to the new `Population` state object.
     */
    void setPopulationState(std::shared_ptr<Population> newState);

    /**
     * @brief Retrieves the current population state.
     * 
     * This method returns a shared pointer to the population state object 
     * being observed by the economy.
     * 
     * @return A shared pointer to the current `Population` state object.
     */
    std::shared_ptr<Population> getState();
};

#endif
