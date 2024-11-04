#ifndef BOYBUILDER_H
#define BOYBUILDER_H

#include "CitizenBuilder.h"
#include "Boy.h"
#include <memory>

/**
 * @class BoyBuilder
 * @brief Concrete implementation of the Builder pattern for creating `Boy` objects.
 * 
 * The `BoyBuilder` class inherits from `CitizenBuilder` and implements the methods required 
 * to construct a `Boy` object. It encapsulates the construction logic and provides a 
 * method to retrieve the final `Boy` instance.
 */
class BoyBuilder : public CitizenBuilder {
private:
    std::shared_ptr<Boy> boy; ///< Shared pointer to the `Boy` object being constructed.
public:
    BoyBuilder();
    /**
     * @brief Adds the gender attribute to the `Boy` object.
     * 
     * This method sets the gender of the `boy` based on specific criteria or user input.
     */
    void addGender();

    /**
     * @brief Adds the type attribute to the `boy` object.
     * 
     * This method sets the type of the `boy`, which is typically a constant value representing 
     * that the citizen is a boy.
     */
    void addType();

    /**
     * @brief Adds the status attribute to the `boy` object.
     * 
     * This method determines and sets the employment or school status of the `Boy`.
     */
    void addStatus(std::string answer);

    /**
     * @brief Retrieves the constructed `boy` object as a `Citizen`.
     * 
     * @return A shared pointer to the constructed `boy` object, cast to the `Citizen` type.
     */
    std::shared_ptr<Citizen> getCitizen();
};

#endif
