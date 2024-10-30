#ifndef CITIZENOBSERVER_H
#define CITIZENOBSERVER_H

/**
 * @class CitizenObserver
 * @brief Abstract base class for observing changes in citizen-related states.
 * 
 * The `CitizenObserver` class defines an interface for observer objects that need to 
 * be notified about changes in the state of citizens or related subjects. 
 * Concrete observer classes must implement the `update()` method to handle 
 * these notifications.
 */
class CitizenObserver {
public:
    /**
     * @brief Updates the observer with the latest changes.
     * 
     * This pure virtual function must be implemented by derived classes to define 
     * how the observer should respond to updates from the subjects it observes.
     */
    virtual void update() = 0; ///< Function to update the observer based on changes in the observed subjects.
};

#endif
