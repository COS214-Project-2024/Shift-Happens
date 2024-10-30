#include "OverPopulated.h"

void OverPopulated::increasePopulation(int increase){
  this->PopulationCount += increase;
}

void OverPopulated::descreasePopulation(int decrease){
  this->PopulationCount -= decrease;

  if(this->PopulationCount < PopOverLowCap){
    this->economy->setPopulationState(std::make_shared<Normal>()); //smart pointer expects make_shared instead of new
  }
}

std::string OverPopulated::getType(){
  return "Over Populated";
}