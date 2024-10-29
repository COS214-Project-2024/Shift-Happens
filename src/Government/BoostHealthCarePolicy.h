#ifndef BOOSTHEALTHCAREPOLICY
#define BOOSTHEALTHCAREPOLICY

#include "Policy.h"
#include "HealthCare.h"
// this policy has a cost, if the budget is enough then it will take education to the next level and build one more education centre or upgrade and existing one
// invoker is the government
// this policy 
// receiver is education

class BoostHealthCarePolicy : public Policy {
  private:
    double Cost = 1000;
    HealthCare* healthcare;
  public:
    void executePolicy(double AvailableBudget);
    BoostHealthCarePolicy(HealthCare* healthcare);
};

#endif