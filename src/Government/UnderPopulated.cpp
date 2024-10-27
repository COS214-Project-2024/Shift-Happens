#include "UnderPopulated.h"

void UnderPopulated::increasePopulation(int increase){
  this->PopulationCount += increase;

  if(this->PopulationCount > PopUnderHighCap){
    this->economy->setPopulationState(new Normal);
  }
}

void UnderPopulated::descreasePopulation(int decrease){
  this->PopulationCount -= decrease;

}

std::string UnderPopulated::getType(){
  return "Under Populated";
}