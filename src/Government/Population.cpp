#include "Population.h"

int Population::getPopulationCount(){
  return this->PopulationCount;
}

void Population::setEconomy(std::shared_ptr<Economy> PassedEconomy){
  this->economy = PassedEconomy;
}