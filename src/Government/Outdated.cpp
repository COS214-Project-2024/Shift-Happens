#include "Outdated.h"
#include <memory>

Outdated::Outdated() : PublicServiceState(){
  this->RunningBudget = 0;
}

Outdated::Outdated(std::shared_ptr<Public_Services> PS) : PublicServiceState(PS){
  this->RunningBudget = 0;
}
void Outdated::increaseBudget(double increase){
  this->RunningBudget += increase;
  if(this->RunningBudget > OutdatedHighCap){
    this->publicServices->setPublicServiceState(std::make_shared<Standard>());
  }

}

void Outdated::decreaseBudget(double decrease){
  this->RunningBudget -= decrease;
}

std::string Outdated::getType(){
  return "Outdated Services";
}