#include "Economy.h"

#include <memory>

void Economy::setPopulationState(std::shared_ptr<Population> newState){
  PopulationState.reset();
  this->PopulationState = newState;
  this->notify();
}

std::shared_ptr<Population> Economy::getState(){
  return PopulationState;
}