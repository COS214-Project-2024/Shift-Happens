#ifndef BOOSTEDUCATIONPOLICY
#define BOOSTEDUCATIONPOLICY

#include "Policy.h"
#include "Education.h"

#include <memory>
// this policy has a cost, if the budget is enough then it will take education to the next level and build one more education centre or upgrade and existing one
// invoker is the government
// this policy 
// receiver is education

/**
 * @class BoostEducatiobPolcy
 * @brief This policy is used when the government decides to boost the current education system. It will take the current education to the next level.
 * 
*/

class BoostEducationPolicy : public Policy {
  private:
  /**
   * @brief Cost holds the price it would cost the government to implement this policy.
   * 
   */
    double Cost = 1000;
    /**
     * @brief education is a shared pointer to the education object that will the receive the upgrades
    */
    std::shared_ptr<Education> education;
  public:
    /**
     * @brief Constructor for the BoostEducationPolicy class
     * @param edu A passed in education object that the class will work with
    */
    BoostEducationPolicy(std::shared_ptr<Education> edu);
    /**
     * @brief executePolicy is the command that is called to execute the policy
     * @param AvailableBudget Is a double value that shows the current budget of the goverment to determine if there is sufficient funds to implement the policy.
    */
    void executePolicy(double AvailableBudget);
    /**
     * @brief This function returns the type of policy.
     * @return The return type is string and will be for example: "Boost Education Policy"
    */
    std::string getPolicyType();
};

#endif