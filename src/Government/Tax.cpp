#include "Tax.h"

double Tax::getRate(){
  return RunningRate;
}

double Tax::getBusinessRate(){
  return RunningRateBusiness;
}