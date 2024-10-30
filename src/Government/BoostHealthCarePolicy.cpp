#include "BoostHealthCarePolicy.h"

#include <iostream>
#include <memory>

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
    std::string currentState = this->healthcare->getState()->getType();
    if(currentState ==  "Modern Services"){
      // build another healthcare centre?
    } else if(currentState == "Standard Services"){
      this->healthcare->setPublicServiceState(std::make_shared<Modern>());
      std::cout << "Your healthcare services was upgraded from standard to modern" << std::endl;
      // build another healthcare centre?
    } else if(currentState == "Outdated Services"){
      this->healthcare->setPublicServiceState(std::make_shared<Standard>());
      std::cout << "Your healthcare services was upgraded from outdated to standard" << std::endl;
      // build another healthcare centre?
    }
  }
}

std::string BoostHealthCarePolicy::getPolicyType(){
  return "Boost Healthcare Policy";
}