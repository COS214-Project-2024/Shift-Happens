#include "Normal.h"

#include "OverPopulated.h"

void Normal::increasePopulation(int increase){
  this->PopulationCount += increase;

  if(this->PopulationCount > PopNormalHighCap){
    this->economy->setPopulationState(new OverPopulated);
  }
}

void Normal::descreasePopulation(int decrease){
  this->PopulationCount -= decrease;

  if(this->PopulationCount < PopNormalLowCap){
    this->economy->setPopulationState(new UnderPopulated);
  }
}

std::string Normal::getType(){
  return "Normal Population";
}