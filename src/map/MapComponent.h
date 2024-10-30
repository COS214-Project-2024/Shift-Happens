#ifndef MAPCOMPONENT_H
#define MAPCOMPONENT_H

#include <string>
#include <iostream>

using namespace std;

/**
 * @brief Abstract base class for map components.
 * 
 * This class provides a common interface for all map components.
 * 
 * @version 1.0
 * @date 2023-10-01
 * 
 * @section author Author
 * Morne van Heerden (u21482153)
 */
class MapComponent
{
private:
    int id; ///< Component ID

public:
    /**
     * @brief Constructor for MapComponent.
     * @param id Component ID.
     */
    MapComponent(int id);

    /**
     * @brief Gets the component ID.
     * @return The component ID.
     */
    int getId();

    /**
     * @brief Pure virtual function to add a component.
     * @param component The component to add.
     * @return True if the component was added, false otherwise.
     */
    virtual bool add(MapComponent *component) = 0;

    /**
     * @brief Pure virtual function to remove a component.
     * @param component The component to remove.
     * @return True if the component was removed, false otherwise.
     */
    virtual bool remove(MapComponent *component) = 0;

    /**
     * @brief Pure virtual function to get a component by ID.
     * @param id The component ID.
     */
    virtual void getComponent(int id) = 0;

    /**
     * @brief Destructor for MapComponent.
     */
    virtual ~MapComponent();

    /**
     * @brief Pure virtual function to render the component.
     */
    virtual void render() = 0;
};

#endif
