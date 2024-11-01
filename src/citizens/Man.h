#ifndef MAN_H
#define MAN_H

#include "Citizen.h"
#include <iostream>
#include <string>

/**
 * @class Man
 * @brief Represents a man as a specific type of citizen.
 * 
 * This class inherits from the `Citizen` base class and defines additional attributes. 
 * It provides methods to access and modify these attributes.
 */
class Man : public Citizen {
private:
    std::string Type; ///< The type is "Man".
    std::string Gender; ///< The gender of the man (e.g., "Male").
    bool Employment; ///< Indicates whether the man is employed (true) or not (false).

public:
    /**
     * @brief Retrieves the type of the man.
     * 
     * @return A string representing the type of the man.
     */
    std::string getType();

    /**
     * @brief Retrieves the gender of the man.
     * 
     * @return A string representing the gender of the man.
     */
    std::string getGender();

    /**
     * @brief Retrieves the employment status of the man.
     * 
     * @return A boolean indicating if the man is employed (true) or not (false).
     */
    bool getStatus();

    /**
     * @brief Sets the type of the man.
     * 
     * @param type A string representing the new type of the man.
     */
    void setType(std::string type);

    /**
     * @brief Sets the gender of the man.
     * 
     * @param gender A string representing the new gender of the man.
     */
    void setGender(std::string gender);

    /**
     * @brief Sets the employment status of the man.
     * 
     * @param status A boolean indicating the new employment status (true for employed, false for not employed).
     */
    void setStatus(bool status);

    /**
     * @brief Sets the employment status.
     * 
     * @param status A boolean indicating if the man is employed (true) or not (false).
     */
    void setEmployment(bool status);

     /**
     * @brief Retrieves a string representation of the object.
     */
    std::string getDescription() const;
};

#endif
