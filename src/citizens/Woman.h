#ifndef WOMAN_H
#define WOMAN_H

#include "Citizen.h"
#include <iostream>
#include <string>

/**
 * @class Woman
 * @brief Represents a woman as a specific type of citizen.
 * 
 * This class inherits from the `Citizen` base class and defines additional attributes. 
 * It provides methods to access and modify these attributes.
 */
class Woman : public Citizen {
private:
    double Income;
    std::string Type; ///< The type is "Woman".
    std::string Gender; ///< The gender of the woman (e.g., "Female").
    bool Employment; ///< Indicates whether the woman is employed (true) or not (false).

public:
    double getIncome();
    /**
     * @brief Retrieves the type of the woman.
     * 
     * @return A string representing the type of the woman.
     */
    std::string getType();

    /**
     * @brief Retrieves the gender of the woman.
     * 
     * @return A string representing the gender of the woman.
     */
    std::string getGender();

    /**
     * @brief Retrieves the employment status of the woman.
     * 
     * @return A boolean indicating if the woman is employed (true) or not (false).
     */
    bool getStatus();

    /**
     * @brief Sets the type of the woman.
     * 
     * @param type A string representing the new type of the woman.
     */
    void setType(std::string type);

    /**
     * @brief Sets the gender of the woman.
     * 
     * @param gender A string representing the new gender of the woman.
     */
    void setGender(std::string gender);

    /**
     * @brief Sets the employment status of the woman.
     * 
     * @param status A boolean indicating the new employment status (true for employed, false for not employed).
     */
    void setStatus(bool status);

    /**
     * @brief Sets the employment status.
     * 
     * @param status A boolean indicating if the woman is employed (true) or not (false).
     */
    void setEmployment(bool status);

    /**
     * @brief Retrieves a string representation of the object.
     */
    std::string getDescription() const;
    void setIncomeRate(double income);
};

#endif
