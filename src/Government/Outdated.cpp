#include "Outdated.h"

void Outdated::increaseBudget(double increase){
  this->RunningBudget += increase;
  if(this->RunningBudget > OutdatedHighCap){
    this->publicServices->setPublicServiceState(new Standard);
  }

}

void Standard::descreaseBudget(double decrease){
  this->RunningBudget -= decrease;
}