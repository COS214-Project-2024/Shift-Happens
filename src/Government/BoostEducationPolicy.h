#ifndef BOOSTEDUCATIONPOLICY
#define BOOSTEDUCATIONPOLICY

#include "Policy.h"
#include "Education.h"

#include <memory>
// this policy has a cost, if the budget is enough then it will take education to the next level and build one more education centre or upgrade and existing one
// invoker is the government
// this policy 
// receiver is education

class BoostEducationPolicy : public Policy {
  private:
    double Cost = 1000;
    std::shared_ptr<Education> education;
  public:
    BoostEducationPolicy(std::shared_ptr<Education> edu);
    void executePolicy(double AvailableBudget);
    std::string getPolicyType();
};

#endif