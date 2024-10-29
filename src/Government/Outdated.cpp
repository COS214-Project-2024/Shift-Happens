#include "Outdated.h"


Outdated::Outdated(){
}
void Outdated::increaseBudget(double increase){
  this->RunningBudget += increase;
  if(this->RunningBudget > OutdatedHighCap){
    this->publicServices->setPublicServiceState(std::make_shared<Standard>());
  }

}

void Outdated::descreaseBudget(double decrease){
  this->RunningBudget -= decrease;
}

std::string Outdated::getType(){
  return "Outdated Services";
}