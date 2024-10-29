#include "Modern.h"

Modern::Modern(){
}
void Modern::increaseBudget(double increase){
  this->RunningBudget += increase;

}

void Modern::descreaseBudget(double decrease){
  this->RunningBudget -= decrease;

  if(this->RunningBudget < ModernLowerCap){
    this->publicServices->setPublicServiceState(std::make_shared<Standard>());
  }
}

std::string Modern::getType(){
  return "Modern Services";
}