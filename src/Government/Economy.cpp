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

void Economy::increasePop(int num){
  PopulationState->increasePopulation(num);
}

void Economy::decreasePop(int num){
  PopulationState->decreasePopulation(num);
}