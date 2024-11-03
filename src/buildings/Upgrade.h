#ifndef UPGRADE_H
#define UPGRADE_H

#include "Building.h"
#include <string>
#include <memory>

/**
 * @class Upgrade
 * @brief Represents an upgrade for a building, enhancing its properties.
 * 
 * This class is derived from the Building class and allows modifications to
 * the waste production, sewage production, electricity demand, and water demand
 * of the underlying building.
 */
class Upgrade : public Building {
protected:
    std::shared_ptr<Building> building; ///< Pointer to the original building being upgraded
    std::string type; ///< Type of upgrade

public:
    /**
     * @brief Constructs an Upgrade object associated with a specified building.
     * @param building A shared pointer to the building being upgraded
     */
    Upgrade(std::shared_ptr<Building> building);
    
    /**
     * @brief Destructor for the Upgrade class.
     */
    virtual ~Upgrade();

    /**
     * @brief Gets the waste produced by the building after upgrade.
     * @return The amount of waste produced
     */
    virtual int getWasteProduced();

    /**
     * @brief Sets the waste produced by the building after upgrade.
     * @param wasteProduced The amount of waste produced to set
     */
    virtual void setWasteProduced(int wasteProduced);

    /**
     * @brief Gets the sewage produced by the building after upgrade.
     * @return The amount of sewage produced
     */
    virtual int getSewageProduced();

    /**
     * @brief Sets the sewage produced by the building after upgrade.
     * @param sewageProduced The amount of sewage produced to set
     */
    virtual void setSewageProduced(int sewageProduced);

    /**
     * @brief Gets the electricity demand of the building after upgrade.
     * @return The electricity demand
     */
    virtual int getElectricityDemand();

    /**
     * @brief Sets the electricity demand of the building after upgrade.
     * @param electricityDemand The electricity demand to set
     */
    virtual void setElectricityDemand(int electricityDemand);

    /**
     * @brief Gets the water demand of the building after upgrade.
     * @return The water demand
     */
    virtual int getWaterDemand();

    /**
     * @brief Sets the water demand of the building after upgrade.
     * @param waterDemand The water demand to set
     */
    virtual void setWaterDemand(int waterDemand);

    /**
     * @brief Gets the type of upgrade.
     * @return The upgrade type as a string
     */
    std::string getUpgradeType();
};

#endif // UPGRADE_H
