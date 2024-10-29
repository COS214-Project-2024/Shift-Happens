#include "BoostEducationPolicy.h"

#include <iostream>
#include "Modern.h"
#include "Standard.h"

void BoostEducationPolicy::executePolicy(double AvailableBudget){
  if(this->Cost > AvailableBudget){
    std::cout << "You currently do not have the funds to fully implements this policy" << std::endl;
  } else {
    if(this->education->getState()->getType() == "Modern Services"){
      // build another education centre
    } else if("Standard Services"){
      this->education->setPublicServiceState(new Modern);
      std::cout << "Your education services was upgraded from standard to modern" << std::endl;
      // build another education centre
    } else if("Outdated Services"){
      this->education->setPublicServiceState(new Standard);
      std::cout << "Your education services was upgraded from outdated to standard" << std::endl;
      // build another education centre
    }
  }
}