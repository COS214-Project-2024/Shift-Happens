#include "Standard.h"

Standard::Standard(){
  this->RunningBudget = StandardLowerCap;
}

Standard::Standard(std::shared_ptr<Public_Services> PS){
  this->publicServices = PS;
}

Standard::Standard(std::shared_ptr<Public_Services> PS, double Budget){
  this->RunningBudget = Budget;
  this->publicServices = PS;
}

void Standard::increaseBudget(double increase){
  this->RunningBudget += increase;
  if(this->RunningBudget > StandardHighCap){
    this->publicServices->setPublicServiceState(std::make_shared<Modern>(publicServices, RunningBudget));
  }

}

void Standard::decreaseBudget(double decrease){
  this->RunningBudget -= decrease;

  if(this->RunningBudget < StandardLowerCap){
    this->publicServices->setPublicServiceState(std::make_shared<Outdated>(this->publicServices));
  }
}

std::string Standard::getType(){
  return "Standard Services";
}