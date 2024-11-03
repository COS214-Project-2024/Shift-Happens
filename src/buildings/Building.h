#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
#include <memory>
#include <string>
#include "../map/MapComponent.h"

/**
 * @class Building
 * @brief Represents a general building structure on the map.
 * 
 * This class provides properties and methods common to all buildings,
 * including dimensions, position, and utility demands.
 */
class Building : public MapComponent {
private:
    int width; ///< Width of the building
    int xPos; ///< X-coordinate position of the building
    int yPos; ///< Y-coordinate position of the building
    int constructionPrice; ///< Construction cost of the building
    int length; ///< Length of the building
    std::string variant; ///< Specific variant of the building
    std::string type; ///< Type or category of the building
    int wasteProduced; ///< Amount of waste produced by the building
    int sewageProduced; ///< Amount of sewage produced by the building
    int electricityDemand; ///< Electricity demand of the building
    int waterDemand; ///< Water demand of the building

protected:

public:
    /**
     * @brief Constructs a Building object with specified parameters.
     * @param id Unique identifier for the building
     * @param width Width of the building
     * @param length Length of the building
     * @param xPos X-coordinate position of the building
     * @param yPos Y-coordinate position of the building
     * @param variant Variant of the building
     * @param type Type of the building
     * @param constructionPrice Construction cost of the building
     * @param wasteProduced Waste produced by the building
     * @param sewageProduced Sewage produced by the building
     * @param electricityDemand Electricity demand of the building
     * @param waterDemand Water demand of the building
     */
    Building(int id, int width, int length, int xPos, int yPos, std::string variant, std::string type, int constructionPrice, int wasteProduced, int sewageProduced, int electricityDemand, int waterDemand);

    /**
     * @brief Constructs a Building object from another building.
     * @param building Shared pointer to another Building object
     */
    Building(shared_ptr<Building> building);

    /**
     * @brief Gets the width of the building.
     * @return Width of the building
     */
    int getWidth();

    /**
     * @brief Renders the building on the map.
     */
    virtual void render();

    /**
     * @brief Sets the width of the building.
     * @param width New width to set
     */
    virtual void setWidth(int width);

    /**
     * @brief Gets the length of the building.
     * @return Length of the building
     */
    virtual int getLength();

    /**
     * @brief Sets the length of the building.
     * @param length New length to set
     */
    virtual void setLength(int length);

    /**
     * @brief Gets the X-coordinate position of the building.
     * @return X-coordinate of the building
     */
    virtual int getXPos();

    /**
     * @brief Sets the X-coordinate position of the building.
     * @param xPos New X-coordinate to set
     */
    virtual void setXPos(int xPos);

    /**
     * @brief Gets the Y-coordinate position of the building.
     * @return Y-coordinate of the building
     */
    virtual int getYPos();

    /**
     * @brief Sets the Y-coordinate position of the building.
     * @param yPos New Y-coordinate to set
     */
    virtual void setYPos(int yPos);

    /**
     * @brief Gets the variant of the building.
     * @return Variant of the building
     */
    virtual std::string getVariant();

    /**
     * @brief Sets the variant of the building.
     * @param variant New variant to set
     */
    virtual void setVariant(std::string variant);

    /**
     * @brief Gets the type of the building.
     * @return Type of the building
     */
    virtual std::string getType();

    /**
     * @brief Sets the type of the building.
     * @param type New type to set
     */
    virtual void setType(std::string type);

    /**
     * @brief Gets the construction price of the building.
     * @return Construction price of the building
     */
    virtual int getConstructionPrice();

    /**
     * @brief Sets the construction price of the building.
     * @param constructionPrice New construction price to set
     */
    virtual void setConstructionPrice(int constructionPrice);

    /**
     * @brief Gets the amount of waste produced by the building.
     * @return Waste produced by the building
     */
    virtual int getWasteProduced();

    /**
     * @brief Sets the amount of waste produced by the building.
     * @param wasteProduced New waste amount to set
     */
    virtual void setWasteProduced(int wasteProduced);

    /**
     * @brief Gets the amount of sewage produced by the building.
     * @return Sewage produced by the building
     */
    virtual int getSewageProduced();

    /**
     * @brief Sets the amount of sewage produced by the building.
     * @param sewageProduced New sewage amount to set
     */
    virtual void setSewageProduced(int sewageProduced);

    /**
     * @brief Gets the electricity demand of the building.
     * @return Electricity demand of the building
     */
    virtual int getElectricityDemand();

    /**
     * @brief Sets the electricity demand of the building.
     * @param electricityDemand New electricity demand to set
     */
    virtual void setElectricityDemand(int electricityDemand);

    /**
     * @brief Gets the water demand of the building.
     * @return Water demand of the building
     */
    virtual int getWaterDemand();

    /**
     * @brief Sets the water demand of the building.
     * @param waterDemand New water demand to set
     */
    virtual void setWaterDemand(int waterDemand);

    /**
     * @brief Prints the building details.
     */
    virtual void print() const;
};

#endif // BUILDING_H
