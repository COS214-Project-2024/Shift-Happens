#include "Standard.h"

Standard::Standard(){
  
}

void Standard::increaseBudget(double increase){
  this->RunningBudget += increase;
  if(this->RunningBudget > StandardHighCap){
    this->publicServices->setPublicServiceState(std::make_shared<Modern>());
  }

}

void Standard::descreaseBudget(double decrease){
  this->RunningBudget -= decrease;

  if(this->RunningBudget < StandardLowerCap){
    this->publicServices->setPublicServiceState(std::make_shared<Outdated>());
  }
}

std::string Standard::getType(){
  return "Standard Services";
}