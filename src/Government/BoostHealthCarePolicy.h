#ifndef BOOSTHEALTHCAREPOLICY
#define BOOSTHEALTHCAREPOLICY

#include "Policy.h"
#include "HealthCare.h"

#include <memory>

/**
 * @class BoostHealthCarePolicy
 * @brief This policy is used when the government decides to boost the current healthcare system. It will enhance healthcare services and facilities.
 * 
 * The BoostHealthCarePolicy class represents a command to improve healthcare by increasing facilities or upgrading existing infrastructure, if the budget permits.
 */
class BoostHealthCarePolicy : public Policy {
  private:

    /**
     * @brief healthcare is a shared pointer to the healthcare object that will receive the upgrades.
     */
    std::shared_ptr<HealthCare> healthcare;

  public:
    BoostHealthCarePolicy();
    /**
     * @brief Constructor for the BoostHealthCarePolicy class.
     * @param healthcare A shared pointer to the healthcare object that the class will work with.
     */
    BoostHealthCarePolicy(std::shared_ptr<HealthCare> healthcare);

    /**
     * @brief Executes the policy to enhance healthcare if the available budget allows.
    */
    void executePolicy();

    /**
     * @brief Returns the type of policy.
     * @return A string indicating the type of policy, e.g., "Boost Healthcare Policy".
     */
    std::string getPolicyType();
};

#endif // BOOSTHEALTHCAREPOLICY
