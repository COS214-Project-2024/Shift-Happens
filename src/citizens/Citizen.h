#ifndef CITIZEN_H
#define CITIZEN_H

#include "CitizenObserver.h"
#include "Director.h"

#include <memory>

#include "../Government/Economy.h"
#include "../Government/Government.h"
#include "../Government/Police.h"
#include "../Government/HealthCare.h"
#include "../Government/Education.h"
#include "../Government/Population.h"
#include "../Government/PublicServiceState.h"
#include "../Government/Tax.h"
#include "../Government/Policy.h"
#include "../Statistics.h" // For tracking statistics and sending data to the statistics object

/**
 * @class Citizen
 * @brief Represents a citizen in the city.
 * 
 * The `Citizen` class is a concrete implementation of the observer abstract class. 
 * It observes changes in government policies, public service states, and population changes. 
 * Each citizen has a satisfaction score (out of 100) indicating their contentment with the current state of the city.
 */

class Statistics; // Forward declaration to avoid circular dependency
class Government;
class Tax;
class Director;
class Citizen : public CitizenObserver {
protected:
    std::shared_ptr<Director> director; ///< Pointer to the director managing the citizens.
    double SatisfactionScore; ///< The highest satisfaction score is 100.
    
    /**
     * @brief The type of citizen (e.g., "Man", "Woman", "Boy", "Girl").
     */
    std::string Type;
    
    std::string Gender; ///< The gender of the citizen.

    /**
     * @brief Status variable indicating employment for adults and school enrollment for minors.
     */
    bool Status;

    // Observer parts
    std::shared_ptr<Economy> economy; ///< Pointer to the economy subject being observed.
    
    /// Pointers to various public services.
    std::shared_ptr<Public_Services> police; ///< Pointer to the police public service.
    std::shared_ptr<Public_Services> education; ///< Pointer to the education public service.
    std::shared_ptr<Public_Services> healthcare; ///< Pointer to the healthcare public service.
    std::shared_ptr<Government> government; ///< Pointer to the government object.

    // States of the concrete subjects being observed.
    std::shared_ptr<Population> observerPopulation; ///< Pointer to the population state.
    std::shared_ptr<PublicServiceState> observerPolice; ///< Pointer to the police service state.
    std::shared_ptr<PublicServiceState> observerEducation; ///< Pointer to the education service state.
    std::shared_ptr<PublicServiceState> observerHealthcare; ///< Pointer to the healthcare service state.
    std::shared_ptr<Tax> observerTax; ///< Pointer to the tax subject being observed.

    std::shared_ptr<Statistics> observerStatistics; ///< Pointer to the statistics object for tracking data.

public:
    /**
     * @brief Updates the citizen based on changes in the states of the subjects being observed.
     * 
     * This observer function is called when there are changes in the states of subjects that the citizen observes.
     */
    void update();

    // Basic attribute accessors
    virtual std::string getType() = 0; ///< Returns the type of the citizen.
    virtual std::string getGender() = 0; ///< Returns the gender of the citizen.
    virtual bool getStatus() = 0; ///< Returns the employment/school status of the citizen.
    virtual void setType(std::string type) = 0; ///< Sets the type of the citizen.
    virtual void setGender(std::string gender) = 0; ///< Sets the gender of the citizen.
    virtual void setStatus(bool status) = 0; ///< Sets the employment/school status of the citizen.

    /**
     * @brief Calculates the satisfaction score of the citizen.
     * 
     * This method considers various factors such as public services, school/work status,
     * and government policies to determine the citizen's satisfaction score out of 100.
     */
    void CalculateSatisfaction();

    /**
     * @brief Retrieves the current satisfaction score of the citizen.
     * 
     * @return The current satisfaction score.
     */
    double getSatisfactionScore();

    /**
     * @brief Increases the satisfaction score by a specified amount.
     * 
     * @param increase The amount to increase the satisfaction score by.
     */
    void increaseSatisfaction(double increase);

    /**
     * @brief Decreases the satisfaction score by a specified amount.
     * 
     * @param decrease The amount to decrease the satisfaction score by.
     */
    void decreaseSatisfaction(double decrease);

    virtual std::string getDescription() const = 0; ///< Returns a string representation of the citizen.
};

#endif
