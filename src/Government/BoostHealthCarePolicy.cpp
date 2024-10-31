#include "BoostHealthCarePolicy.h"

#include <iostream>
#include <memory>

#include "Modern.h"
#include "Standard.h"

BoostHealthCarePolicy::BoostHealthCarePolicy(){
  this->Cost = 1000;
}

BoostHealthCarePolicy::BoostHealthCarePolicy(std::shared_ptr<HealthCare> healthcare){
  this->healthcare = healthcare;
  this->Cost = 1000;
}

void BoostHealthCarePolicy::executePolicy(){
    std::string currentState = this->healthcare->getState()->getType();
    if(currentState ==  "Modern Services"){
      // build another healthcare centre?
      std::cout << "Your healthcare services are already at the highest level" << std::endl;
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

std::string BoostHealthCarePolicy::getPolicyType(){
  return "Boost Healthcare Policy";
}