#include "Economy.h"

void Economy::setPopulationState(Population* newState){
  if(PopulationState != nullptr){
    delete PopulationState;
  }
  this->PopulationState = newState;
  this->notify();
}

Population* Economy::getState(){
  return PopulationState;
}