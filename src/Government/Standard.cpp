#include "Standard.h"

Standard::Standard(){
  
}

void Standard::increaseBudget(double increase){
  this->RunningBudget += increase;
  if(this->RunningBudget > StandardHighCap){
    this->publicServices->setPublicServiceState(new Modern);
  }

}

void Standard::descreaseBudget(double decrease){
  this->RunningBudget -= decrease;

  if(this->RunningBudget < StandardLowerCap){
    this->publicServices->setPublicServiceState(new Outdated);
  }
}

std::string Standard::getType(){
  return "Standard Services";
}