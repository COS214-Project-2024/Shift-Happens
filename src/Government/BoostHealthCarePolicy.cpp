#include "BoostHealthCarePolicy.h"

#include <iostream>
#include "Modern.h"
#include "Standard.h"

BoostHealthCarePolicy::BoostHealthCarePolicy(std::shared_ptr<HealthCare> healthcare){
  this->healthcare = healthcare;
}

void BoostHealthCarePolicy::executePolicy(double AvailableBudget){
  if(this->Cost > AvailableBudget){
    std::cout << "You currently do not have the funds to fully implements this policy" << std::endl;
    return; //Not enough funds to implement policy
  } else {
    if(this->healthcare->getState()->getType() == "Modern Services"){
      // build another healthcare centre?
    } else if("Standard Services"){
      this->healthcare->setPublicServiceState(new Modern);
      std::cout << "Your healthcare services was upgraded from standard to modern" << std::endl;
      // build another healthcare centre?
    } else if("Outdated Services"){
      this->healthcare->setPublicServiceState(new Standard);
      std::cout << "Your healthcare services was upgraded from outdated to standard" << std::endl;
      // build another healthcare centre?
    }
  }
}