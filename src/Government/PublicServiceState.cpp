#include "PublicServiceState.h"

void PublicServiceState::setPublicService(std::shared_ptr<Public_Services> publicService){
  this->publicServices = publicService;
}

double PublicServiceState::getRunningBudget(){
  return this->RunningBudget;
}