#ifndef PUBLICSERVICES_H
#define PUBLICSERVICES_H

#include "CitySubject.h"
#include "PublicServiceState.h"

#include <iostream>

// Concrete subject in observer pattern
// Context in state pattern

/**
 * @class Public_Services
 * @brief Abstract base class for all types of public services in a city.
 * 
 * This class represents the common interface for various public services, 
 * such as Police, Education, and Healthcare. It acts as a concrete subject 
 * in the observer pattern, allowing observers to be notified of state changes. 
 * Additionally, it serves as a context in the state pattern, managing the 
 * current state of the public service.
 */
class PublicServiceState; // Forward declaration to avoid circular dependency
class Public_Services : public CitySubject {
public:
    /**
     * @brief Delegates funding to the specific public service.
     * 
     * This template method orchestrates the allocation of funds by calling 
     * the pure virtual functions that handle the specifics of increasing 
     * or decreasing the budget in the derived classes.
     */
    void DelegateFunds(std::string answer);

    /**
     * @brief Sets the state of the public service.
     * 
     * @param newState A shared pointer to the new state object that the 
     * public service should transition to.
     */
    virtual void setPublicServiceState(std::shared_ptr<PublicServiceState> newState) = 0;

    /**
     * @brief Retrieves the current state of the public service.
     * 
     * @return A shared pointer to the state object representing the 
     * current state of the public service.
     */
    virtual std::shared_ptr<PublicServiceState> getState() = 0;

    /**
     * @brief Retrieves the type of public service.
     * 
     * This method returns a string that identifies the specific type of 
     * public service (e.g., "Police", "Education", "Healthcare").
     * 
     * @return A string representing the type of public service.
     */
    virtual std::string getTypeOfPublicService() = 0;

    /**
     * @brief Handles the increase of the public service budget.
     * 
     * This method will contain the logic to allocate additional funds 
     * to the public service.
     */
    virtual void increaseBudget() = 0;

    /**
     * @brief Handles the decrease of the public service budget.
     * 
     * This method will contain the logic to reduce the budget allocated 
     * to the public service.
     */
    virtual void decreaseBudget() = 0;
};

#endif
