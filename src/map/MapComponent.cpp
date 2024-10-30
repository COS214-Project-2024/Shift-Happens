#include "MapComponent.h"

/**
 * @brief Constructor for MapComponent.
 * @param id Component ID.
 */
MapComponent::MapComponent(int id) {
    this->id = id;
}

/**
 * @brief Destructor for MapComponent.
 */
MapComponent::~MapComponent() {
}

/**
 * @brief Gets the component ID.
 * @return The component ID.
 */
int MapComponent::getId() {
    return id;
}


