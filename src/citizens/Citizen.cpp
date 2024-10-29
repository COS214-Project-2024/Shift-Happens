#include "Citizen.h"

void Citizen::update(){
  observerPopulation = economy->getState();
  observerPolice = police->getState();
  observerEducation = education->getState();
  observerHealthcare = healthcare->getState();
  observerTax = government->getTax();
  observerPolicy = government->getPolicies();

  CalculateSatisfaction();
} 

void Citizen::CalculateSatisfaction(){
  // employed or in school, population : falls under quality of life
  // availability of public services: falls under amenities
  // taxes

  // 1. School/Employment = 20 points
  // 2. Availability of public services: Modern 20 points, Standard 10 points, Outdated - 10 points
  // 3. Population: Over populated = - 5 points, Normal 10 Points, Under populated - 5 points
  // 4. Tax: High - 10 points, Standard 10 points, Low 20 points

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

  // education services
  if(observerEducation->getType() == "Modern Services"){
    if(this->getType() == "Boy" || this->getType() == "Girl"){
      Total += 10;
    } else {
      Total += 5;
    }
  } else if(observerEducation->getType() == "Standard Services"){
    if(this->getType() == "Boy" || this->getType() == "Girl"){
      Total += 5;
    }
    Total += 2;
  } else if(observerEducation->getType() == "Outdated Services"){
    if(this->getType() == "Boy" || this->getType() == "Girl"){
      Total -= 10;
    }
    Total -= 5;
  }

  // police services
  if(observerEducation->getType() == "Modern Services"){
    if(this->getType() == "Boy" || this->getType() == "Girl"){
      Total += 10;
    } else {
      Total += 5;
    }
  } else if(observerEducation->getType() == "Standard Services"){
    if(this->getType() == "Boy" || this->getType() == "Girl"){
      Total += 5;
    }
    Total += 2;
  } else if(observerEducation->getType() == "Outdated Services"){
    if(this->getType() == "Boy" || this->getType() == "Girl"){
      Total -= 10;
    }
    Total -= 5;
  }

  // healthcare
  if(observerEducation->getType() == "Modern Services"){
    Total += 5;
  } else if(observerEducation->getType() == "Standard Services"){
    Total += 2;
  } else if(observerEducation->getType() == "Outdated Services"){
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

  // tax
  if(observerTax->getType() == "High Tax"){
    if(this->getType() == "Man" || this->getType() == "Woman"){
      Total -= 20;
    }
  } else if(observerTax->getType() == "Standard Tax"){
    if(this->getType() == "Man" || this->getType() == "Woman"){
      Total += 5;
    }
  } else if(observerTax->getType() == "Low Tax"){
    if(this->getType() == "Man" || this->getType() == "Woman"){
      Total += 10;
    }
  }

  this->SatisfactionScore = Total;
}

double Citizen::getSatisfactionScore(){
  return this->SatisfactionScore;
}

void Citizen::increaseSatisfaction(double increase){
  this->SatisfactionScore += increase;
}

void Citizen::decreaseSatisfaction(double decrease){
  this->SatisfactionScore -= decrease;
}