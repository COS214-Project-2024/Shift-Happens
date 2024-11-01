#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "CitizenBuilder.h"
#include <memory>

/**
 * @class Director
 * @brief The Director class orchestrates the construction of `Citizen` objects using the Builder design pattern.
 * 
 * The `Director` maintains a shared pointer to a `CitizenBuilder` and is responsible for 
 * coordinating the building process. It defines the order of operations required to construct 
 * a complete `Citizen` object, ensuring that all necessary attributes are set correctly.
 */
class CitizenBuilder;
class Director {
private:
    std::shared_ptr<CitizenBuilder> Builder; ///< Shared pointer to the `CitizenBuilder` used for constructing citizens.

public:
    /**
     * @brief Constructs a `Citizen` object using the associated `CitizenBuilder`.
     * 
     * This method instructs the builder to set the necessary attributes and finalize the 
     * construction of a `Citizen` instance. The specific steps involved in the construction 
     * are defined within the builder implementation.
     */
    void construct();
};

#endif
