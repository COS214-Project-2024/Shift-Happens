#ifndef BOOSTPOLICEPOLICY
#define BOOSTPOLICEPOLICY

#include "Policy.h"
#include "Police.h"

#include <memory>
// this policy has a cost, if the budget is enough then it will take police to the next level and build one more police centre or upgrade and existing one
// invoker is the government
// this policy 
// receiver is police

class BoostPolicePolicy : public Policy {
  private:
    double Cost = 1000;
    std::shared_ptr<Police> police;
  public:
    void executePolicy(double AvailableBudget);
    BoostPolicePolicy(std::shared_ptr<Police> police);
    std::string getPolicyType();
};

#endif