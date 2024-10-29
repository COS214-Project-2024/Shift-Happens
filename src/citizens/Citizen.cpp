#include "Citizen.h"

void Citizen::update(){
  observerPopulation = economy->getState();
  observerPublicServiceState = infrastructure->getState();
  observerTax = government->getTax();
  observerPolicy = government->getPolicies();
}

void Citizen::CalculateSatisfaction(){
  // employed or in school, population : falls under quality of life
  // availability of public services: falls under amenities
  // taxes

  // 1. School/Employment = 20 points
  // 2. Availability of public services: Modern 20 points, Standard 10 points, Outdated - 10 points
  // 3. Population: Over populated = - 5 points, Normal 10 Points, Under populated - 5 points
  // 4. Tax: High - 10 points, Standard 10 points, Low 20 points
  // 5. Policies: 

  double Total = 0;
  // shcool and work
  if(this->getType() == "Man" || this->getType() == "Woman"){
    if(this->getStatus()){
      Total += 20;
    }
  } else if(this->getType() == "Boy" || this->getType() == "Girl"){
    if(this->getStatus()){
      Total += 20;
    }
  }

  // public services
  if(observerPublicServiceState->getType() == "Modern Services"){
    Total += 20;
  } else if(observerPublicServiceState->getType() == "Standard Services"){
    Total += 10;
  } else if(observerPublicServiceState->getType() == "Outdated Services"){
    Total -= 10;
  }

  // Population
  if(observerPopulation->getType() == "Over Populated"){
    Total -= 5;
  } else if(observerPopulation->getType() == "Normal Populated"){
    Total += 10;
  } else if(observerPopulation->getType() == "Under Populated"){
    Total -= 5;
  }
}

double Citizen::getSatisfactionScore(){
  return this->SatisfactionScore;
}