#ifndef GIRLBUILDER_H
#define GIRLBUILDER_H

#include "CitizenBuilder.h"
#include "Girl.h"

/**
 * @class GirlBuilder
 * @brief Concrete implementation of the Builder pattern for creating `Girl` objects.
 * 
 * The `GirlBuilder` class inherits from `CitizenBuilder` and implements the methods required 
 * to construct a `Girl` object. It encapsulates the construction logic and provides a 
 * method to retrieve the final `Girl` instance.
 */
class GirlBuilder : public CitizenBuilder {
private:
    std::shared_ptr<Girl> girl; ///< Shared pointer to the `Girl` object being constructed.
    int CreatorCounter =0;
public:
    GirlBuilder();
    /**
     * @brief Adds the gender attribute to the `Girl` object.
     * 
     * This method sets the gender of the `Girl` based on specific criteria or user input.
     */
    void addGender();

    /**
     * @brief Adds the type attribute to the `Girl` object.
     * 
     * This method sets the type of the `Girl`, which is typically a constant value representing 
     * that the citizen is a girl.
     */
    void addType();

    /**
     * @brief Adds the status attribute to the `Girl` object.
     * 
     * This method determines and sets the employment or school status of the `Girl`.
     */
    void addStatus();

    /**
     * @brief Retrieves the constructed `Girl` object as a `Citizen`.
     * 
     * @return A shared pointer to the constructed `Girl` object, cast to the `Citizen` type.
     */
    std::shared_ptr<Citizen> getCitizen();
};

#endif
