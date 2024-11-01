#ifndef CITIZENBUILDER_H
#define CITIZENBUILDER_H

#include <memory>
#include "../citizens/Citizen.h"


/**
 * @class CitizenBuilder
 * @brief Abstract base class that defines the interface for building `Citizen` objects.
 * 
 * The `CitizenBuilder` class implements the Builder design pattern, allowing for 
 * the step-by-step construction of `Citizen` instances. It provides methods to 
 * specify the attributes of the citizen being built, such as gender, type, and status.
 */

class Citizen;
class CitizenBuilder {
public:
    /**
     * @brief Adds gender information to the citizen being built.
     * 
     * This method should be implemented by derived classes to specify how the 
     * gender is set for the citizen instance.
     */
    virtual void addGender() = 0;

    /**
     * @brief Adds type information to the citizen being built.
     * 
     * This method should be implemented by derived classes to specify how the 
     * type is set for the citizen instance.
     */
    virtual void addType() = 0;

    /**
     * @brief Adds status information to the citizen being built.
     * 
     * This method should be implemented by derived classes to specify how the 
     * employment or school status is set for the citizen instance.
     */
    virtual void addStatus() = 0;

    /**
     * @brief Retrieves the constructed citizen object.
     * 
     * @return A shared pointer to the constructed `Citizen` object.
     * 
     * This method should be implemented by derived classes to return the 
     * finalized citizen instance.
     */
    virtual std::shared_ptr<Citizen> getCitizen() = 0;
};

#endif
