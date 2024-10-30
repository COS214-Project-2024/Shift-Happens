#include "BoostPolicePolicy.h"

#include <iostream>
#include <memory>
#include "Modern.h"
#include "Standard.h"


BoostPolicePolicy::BoostPolicePolicy(std::shared_ptr<Police> police){
  this->police = police;
}

void BoostPolicePolicy::executePolicy(double AvailableBudget){
  if(this->Cost > AvailableBudget){
    std::cout << "You currently do not have the funds to fully implements this policy" << std::endl;
  } else {
    std::string currentState = this->police->getState()->getType();
    if(currentState ==  "Modern Services"){
      // build another police centre?
    } else if(currentState ==  "Standard Services"){
      this->police->setPublicServiceState(std::make_shared<Modern>());
      std::cout << "Your police services was upgraded from standard to modern" << std::endl;
      // build another police centre?
    } else if(currentState ==  "Outdated Services"){
      this->police->setPublicServiceState(std::make_shared<Standard>());
      std::cout << "Your police services was upgraded from outdated to standard" << std::endl;
      // build another police centre?
    }
  }
}

std::string BoostPolicePolicy::getPolicyType(){
  return "Boost Police Policy";
}