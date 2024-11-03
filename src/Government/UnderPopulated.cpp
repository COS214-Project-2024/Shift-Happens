#include "UnderPopulated.h"

#include <memory>

UnderPopulated::UnderPopulated(){
  this->PopulationCount = 0;
}

UnderPopulated::UnderPopulated(int count){
  this->PopulationCount = count;
}

void UnderPopulated::increasePopulation(int increase){
  this->PopulationCount += increase;

  if(this->PopulationCount > PopUnderHighCap){
    this->economy->setPopulationState(std::make_shared<Normal>());
  }
}

void UnderPopulated::decreasePopulation(int decrease){
  this->PopulationCount -= decrease;
  if(this->PopulationCount < 0){
    this->PopulationCount = 0;
  }
}

std::string UnderPopulated::getType(){
  return "Under Populated";
}