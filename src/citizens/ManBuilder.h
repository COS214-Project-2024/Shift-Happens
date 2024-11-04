#ifndef MANBUILDER_H
#define MANBUILDER_H

#include "Man.h"
#include "CitizenBuilder.h"

/**
 * @class ManBuilder
 * @brief Concrete implementation of the Builder pattern for creating `Man` objects.
 * 
 * The `ManBuilder` class inherits from `CitizenBuilder` and implements the methods required 
 * to construct a `Man` object. It encapsulates the construction logic and provides a 
 * method to retrieve the final `Man` instance.
 */
class ManBuilder : public CitizenBuilder {
private:
    std::shared_ptr<Man> man; ///< Shared pointer to the `Man` object being constructed.
    int CreatorCounter = 0;
public:
    ManBuilder();
    /**
     * @brief Adds the gender attribute to the `Man` object.
     * 
     * This method sets the gender of the `Man` based on specific criteria or user input.
     */
    void addGender();

    /**
     * @brief Adds the type attribute to the `Man` object.
     * 
     * This method sets the type of the `Man`, which is typically a constant value representing 
     * that the citizen is a man.
     */
    void addType();

    /**
     * @brief Adds the status attribute to the `Man` object.
     * 
     * This method determines and sets the employment status of the `Man`.
     */
    void addStatus();

    /**
     * @brief Retrieves the constructed `Man` object as a `Citizen`.
     * 
     * @return A shared pointer to the constructed `Man` object, cast to the `Citizen` type.
     */
    std::shared_ptr<Citizen> getCitizen();
};

#endif
