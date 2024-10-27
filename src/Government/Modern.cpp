#include "Modern.h"

void Modern::increaseBudget(double increase){
  this->RunningBudget += increase;

}

void Modern::descreaseBudget(double decrease){
  this->RunningBudget -= decrease;

  if(this->RunningBudget < ModernLowerCap){
    this->publicServices->setPublicServiceState(new Standard);
  }
}