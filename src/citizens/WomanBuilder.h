#ifndef WOMANBUILDER_H
#define WOMANBUILDER_H

#include "CitizenBuilder.h"
#include "Woman.h"

/**
 * @class WomanBuilder
 * @brief Concrete implementation of the Builder pattern for creating `Woman` objects.
 * 
 * The `WomanBuilder` class inherits from `CitizenBuilder` and implements the methods required 
 * to construct a `Woman` object. It encapsulates the construction logic and provides a 
 * method to retrieve the final `Woman` instance.
 */
class WomanBuilder : public CitizenBuilder {
private:
    std::shared_ptr<Woman> woman; ///< Shared pointer to the `Woman` object being constructed.
public:
    WomanBuilder();
    /**
     * @brief Adds the gender attribute to the `Woman` object.
     * 
     * This method sets the gender of the `Woman` based on specific criteria or user input.
     */
    void addGender();

    /**
     * @brief Adds the type attribute to the `Woman` object.
     * 
     * This method sets the type of the `Woman`, which is typically a constant value representing 
     * that the citizen is a woman.
     */
    void addType();

    /**
     * @brief Adds the status attribute to the `Woman` object.
     * 
     * This method determines and sets the employment status of the `Woman`.
     */
    void addStatus(std::string answer);

    /**
     * @brief Retrieves the constructed `Woman` object as a `Citizen`.
     * 
     * @return A shared pointer to the constructed `Woman` object, cast to the `Citizen` type.
     */
    std::shared_ptr<Citizen> getCitizen();
};

#endif
