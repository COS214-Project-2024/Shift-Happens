#ifndef GIRL_H
#define GIRL_H

#include "Citizen.h"
#include <string>

/**
 * @class Girl
 * @brief Represents a girl as a specific type of citizen.
 * 
 * This class inherits from the `Citizen` base class and defines additional attributes. 
 * It provides methods to access and modify these attributes.
 */
class Girl : public Citizen {
private:
    std::string Type; ///< The type is "Girl".
    std::string Gender; ///< The gender of the girl (e.g., "Female").
    bool School; ///< Indicates whether the girl is enrolled in school (true) or not (false).

public:
    /**
     * @brief Retrieves the type of the girl.
     * 
     * @return A string representing the type of the girl.
     */
    std::string getType();

    /**
     * @brief Retrieves the gender of the girl.
     * 
     * @return A string representing the gender of the girl.
     */
    std::string getGender();

    /**
     * @brief Retrieves the school enrollment status of the girl.
     * 
     * @return A boolean indicating if the girl is enrolled in school (true) or not (false).
     */
    bool getStatus();

    /**
     * @brief Sets the type of the girl.
     * 
     * @param type A string representing the new type of the girl.
     */
    void setType(std::string type);

    /**
     * @brief Sets the gender of the girl.
     * 
     * @param gender A string representing the new gender of the girl.
     */
    void setGender(std::string gender);

    /**
     * @brief Sets the school enrollment status of the girl.
     * 
     * @param status A boolean indicating the new enrollment status (true for enrolled, false for not enrolled).
     */
    void setStatus(bool status);

    /**
     * @brief Sets the school enrollment status.
     * 
     * @param status A boolean indicating if the girl is in school (true) or not (false).
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
