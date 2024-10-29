#include "BoostPolicePolicy.h"

#include <iostream>
#include "Modern.h"
#include "Standard.h"

BoostPolicePolicy::BoostPolicePolicy(std::shared_ptr<Police> police){
  this->police = police;
}

void BoostPolicePolicy::executePolicy(double AvailableBudget){
  if(this->Cost > AvailableBudget){
    std::cout << "You currently do not have the funds to fully implements this policy" << std::endl;
  } else {
    if(this->police->getState()->getType() == "Modern Services"){
      // build another police centre?
    } else if("Standard Services"){
      this->police->setPublicServiceState(new Modern);
      std::cout << "Your police services was upgraded from standard to modern" << std::endl;
      // build another police centre?
    } else if("Outdated Services"){
      this->police->setPublicServiceState(new Standard);
      std::cout << "Your police services was upgraded from outdated to standard" << std::endl;
      // build another police centre?
    }
  }
}