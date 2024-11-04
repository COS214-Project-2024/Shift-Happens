#include "Modern.h"

Modern::Modern(){
  this->RunningBudget = ModernLowerCap;
}

Modern::Modern(std::shared_ptr<Public_Services> PS){
  this->publicServices = PS;
}
Modern::Modern(std::shared_ptr<Public_Services> PS, double Budget){
  this->RunningBudget = Budget;
  this->publicServices = PS;
}

void Modern::increaseBudget(double increase){
  this->RunningBudget += increase;

}

void Modern::decreaseBudget(double decrease){
  this->RunningBudget -= decrease;

  if(this->RunningBudget < ModernLowerCap){
    this->publicServices->setPublicServiceState(std::make_shared<Standard>(publicServices,RunningBudget));
  }
}

std::string Modern::getType(){
  return "Modern Services";
}