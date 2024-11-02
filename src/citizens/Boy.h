#ifndef BOY_H
#define BOY_H

#include "Citizen.h"
#include <string>
#include <memory>

/**
 * @class Boy
 * @brief Represents a boy as a specific type of citizen.
 * 
 * This class inherits from the `Citizen` base class and defines additional attributes. 
 * It provides methods to access and modify these attributes.
 */
class Boy : public Citizen {
private:
    std::string Type; ///< The type is "Boy"
    std::string Gender; ///< The gender of the boy (e.g., "Male").
    bool School; ///< Indicates whether the boy is enrolled in school (true) or not (false).

public:
    /**
     * @brief Retrieves the type of the boy.
     * 
     * @return A string representing the type of the boy.
     */
    std::string getType();

    /**
     * @brief Retrieves the gender of the boy.
     * 
     * @return A string representing the gender of the boy.
     */
    std::string getGender();

    /**
     * @brief Retrieves the school enrollment status of the boy.
     * 
     * @return A boolean indicating if the boy is enrolled in school (true) or not (false).
     */
    bool getStatus();

    /**
     * @brief Sets the type of the boy.
     * 
     * @param type A string representing the new type of the boy.
     */
    void setType(std::string type);

    /**
     * @brief Sets the gender of the boy.
     * 
     * @param gender A string representing the new gender of the boy.
     */
    void setGender(std::string gender);

    /**
     * @brief Sets the school enrollment status of the boy.
     * 
     * @param status A boolean indicating the new enrollment status (true for enrolled, false for not enrolled).
     */
    void setStatus(bool status);

    /**
     * @brief Sets the school enrollment status.
     * 
     * @param status A boolean indicating if the boy is in school (true) or not (false).
     */
    void setSchool(bool status);

    /**
     * @brief Retrieves a string representation of the object.
     */
    std::string getDescription() const;

    void setIncomeRate(double income);
    double getIncome();
};

#endif
