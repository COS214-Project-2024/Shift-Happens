#include "Normal.h"

#include "OverPopulated.h"
using namespace std;

void Normal::increasePopulation(int increase){
  this->PopulationCount += increase;

  if(this->PopulationCount > PopNormalHighCap){
    this->economy->setPopulationState(make_shared<OverPopulated>());
  }
}

void Normal::decreasePopulation(int decrease){
  this->PopulationCount -= decrease;

  if(this->PopulationCount < PopNormalLowCap){
    this->economy->setPopulationState(make_shared<UnderPopulated>());
  }
}

std::string Normal::getType(){
  return "Normal Population";
}