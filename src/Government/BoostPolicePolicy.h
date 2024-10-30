#ifndef BOOSTPOLICEPOLICY
#define BOOSTPOLICEPOLICY

#include "Policy.h"
#include "Police.h"

#include <memory>

/**
 * @class BoostPolicePolicy
 * @brief This policy is used when the government decides to enhance the current police system. It will upragde the police system.
 * 
 * The BoostPolicePolicy class represents a command to improve police infrastructure, either by adding a new police center or upgrading an existing one, if the budget permits.
 */
class BoostPolicePolicy : public Policy {
  private:
    /**
     * @brief Cost holds the amount required by the government to implement this policy.
     */
    double Cost = 1000;

    /**
     * @brief police is a shared pointer to the Police object that will receive the upgrades.
     */
    std::shared_ptr<Police> police;

  public:
    /**
     * @brief Constructor for the BoostPolicePolicy class.
     * @param police A shared pointer to the Police object that the class will work with.
     */
    BoostPolicePolicy(std::shared_ptr<Police> police);

    /**
     * @brief Executes the policy to enhance police services if the available budget allows.
     * @param AvailableBudget The current budget available to determine if there are sufficient funds to implement the policy.
     */
    void executePolicy(double AvailableBudget);

    /**
     * @brief Returns the type of policy.
     * @return A string indicating the type of policy, e.g., "Boost Police Policy".
     */
    std::string getPolicyType();
};

#endif // BOOSTPOLICEPOLICY
