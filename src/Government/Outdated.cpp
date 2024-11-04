#include "Outdated.h"
#include <memory>

Outdated::Outdated() : PublicServiceState(){
  this->RunningBudget = 0;
}

Outdated::Outdated(std::shared_ptr<Public_Services> PS) : PublicServiceState(PS){
  this->RunningBudget = 0;
}

Outdated::Outdated(std::shared_ptr<Public_Services> PS, double Budget){
  this->RunningBudget = Budget;
  this->publicServices = PS;
}

void Outdated::increaseBudget(double increase){
  this->RunningBudget += increase;
  if(this->RunningBudget > OutdatedHighCap){
    this->publicServices->setPublicServiceState(std::make_shared<Standard>(publicServices,RunningBudget));
  }

}

void Outdated::decreaseBudget(double decrease){
  this->RunningBudget -= decrease;
}

std::string Outdated::getType(){
  return "Outdated Services";
}