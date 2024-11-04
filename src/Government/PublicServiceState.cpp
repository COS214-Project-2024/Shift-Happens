#include "PublicServiceState.h"
#include <memory>

void PublicServiceState::setPublicService(std::shared_ptr<Public_Services> publicService){
  this->publicServices = publicService;
}

double PublicServiceState::getRunningBudget(){
  return this->RunningBudget;
}

PublicServiceState::PublicServiceState(std::shared_ptr<Public_Services> PS){
  this->publicServices = PS;
  RunningBudget = 0;
}

PublicServiceState::PublicServiceState(){
  RunningBudget = 0;
}