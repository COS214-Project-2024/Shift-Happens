#include "Tax.h"

Tax::Tax(std::shared_ptr<Government> government){
  this->government = government;
}

double Tax::getRate(){
  return RunningRate;
}

double Tax::getBusinessRate(){
  return RunningRateBusiness;
}

void Tax::setBusinessRate(double rate){
  this->RunningRateBusiness = rate;
}

void Tax::setPersonalRate(double rate){
  this->RunningRate = rate;
}