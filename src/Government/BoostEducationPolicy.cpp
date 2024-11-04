#include "BoostEducationPolicy.h"

#include <iostream>
#include <memory>

#include "Modern.h"
#include "Standard.h"

BoostEducationPolicy::BoostEducationPolicy(){
  this->Cost = 1000;
}

BoostEducationPolicy::BoostEducationPolicy(std::shared_ptr<Education> edu){
  this->education = edu;
  this->Cost = 1000;
}

void BoostEducationPolicy::executePolicy(){
     std::string currentState = this->education->getState()->getType();
    if(currentState == "Modern Services"){
      // build another education centre
      std::cout << "Your education services are already at the highest level" << std::endl;
    } else if(currentState ==  "Standard Services"){
      this->education->setPublicServiceState(std::make_shared<Modern>());
      std::cout << "Your education services was upgraded from standard to modern" << std::endl;
      // build another education centre
    } else if(currentState ==  "Outdated Services"){
      this->education->setPublicServiceState(std::make_shared<Standard>());
      std::cout << "Your education services was upgraded from outdated to standard" << std::endl;
      // build another education centre
    }
}

std::string BoostEducationPolicy::getPolicyType(){
  return "Boost Education Policy";
}