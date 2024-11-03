#ifndef MATERIALS_H
#define MATERIALS_H

#include <iostream>
#include <string>
#include <vector>

/**
 * @class Materials
 * @brief Represents materials used in construction or other applications.
 * 
 * This class encapsulates the description, cost, and quantity of materials.
 */
class Materials {
private:
    std::string description; ///< Description of the material
    double cost; ///< Cost of the material per unit
    int quantity; ///< Quantity of the material available

public:
    /**
     * @brief Constructs a Materials object with specified parameters.
     * @param description Description of the material
     * @param cost Cost of the material per unit
     * @param quantity Quantity of the material available
     */
    Materials(std::string description, double cost, int quantity);
};

#endif // MATERIALS_H
