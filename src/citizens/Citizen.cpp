#include "Citizen.h"
#include <memory>
#include <sys/wait.h>

Citizen::Citizen(){

}

Citizen::Citizen(std::shared_ptr<Public_Services> police,std::shared_ptr<Public_Services> education,std::shared_ptr<Public_Services> healthcare, std::shared_ptr<Government> government,std::shared_ptr<Economy> economy){
  this->police = police;
  this->education = education;
  this->healthcare = healthcare;
  this->government = government;
  this->economy = economy;
}

void Citizen::setPolice(std::shared_ptr<Public_Services> police){
  this->police = police;
  this->observerPolice = this->police->getState();
}

void Citizen::setEducation(std::shared_ptr<Education> education){
  this->education = education;
  this->observerEducation = this->education->getState();
}

void Citizen::setHealthcare(std::shared_ptr<Public_Services> healthcare){
  this->healthcare = healthcare;
  this->observerHealthcare = this->healthcare->getState();
}

void Citizen::setGovernment(std::shared_ptr<Government> government){
  this->government = government;
  this->observerTax = this->government->getTax();
}

void Citizen::setEconomy( std::shared_ptr<Economy> economy){
  this->economy = economy;
  this->observerPopulation = this->economy->getState();
}

void Citizen::update(){
    cout << "Citizen notified" << endl;
  observerPopulation = economy->getState();
  observerPolice = police->getState();
  observerEducation = education->getState();
  observerHealthcare = healthcare->getState();
  observerTax = government->getTax();

  if(observerTax->getType() == "High Tax"){
    this->setIncomeRate(15000);
  } else if(observerTax->getType() == "Standard Tax"){
    this->setIncomeRate(10000);
  } else if(observerTax->getType() == "Low Tax"){
    this->setIncomeRate(5000);
  }

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
      Total += 30;
    } else {
      Total += 20;
    }
  } else if(observerEducation->getType() == "Standard Services"){
    if(this->getType() == "Boy" || this->getType() == "Girl"){
      Total += 20;
    }
    Total += 10;
  } else if(observerEducation->getType() == "Outdated Services"){
    if(this->getType() == "Boy" || this->getType() == "Girl"){
      Total += 0;
    }
    Total += 0 ;
  }

  // police services
  if(observerEducation->getType() == "Modern Services"){
    if(this->getType() == "Boy" || this->getType() == "Girl"){
      Total += 30;
    } else {
      Total += 20;
    }
  } else if(observerEducation->getType() == "Standard Services"){
    if(this->getType() == "Boy" || this->getType() == "Girl"){
      Total += 20;
    }
    Total += 10;
  } else if(observerEducation->getType() == "Outdated Services"){
    if(this->getType() == "Boy" || this->getType() == "Girl"){
      Total += 0;
    }
    Total += 0;
  }

  // healthcare
  if(observerEducation->getType() == "Modern Services"){
    Total += 20;
  } else if(observerEducation->getType() == "Standard Services"){
    Total += 10;
  } else if(observerEducation->getType() == "Outdated Services"){
    Total += 0;
  }

  // Population
  if(observerPopulation->getType() == "Over Populated"){
    Total += 0;
  } else if(observerPopulation->getType() == "Normal Populated"){
    Total += 20;
  } else if(observerPopulation->getType() == "Under Populated"){
    Total += 0;
  }

  // tax
  if(observerTax->getType() == "High Tax"){
    if(this->getType() == "Man" || this->getType() == "Woman"){
      Total -= 10;
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
  CalculateSatisfaction();
  return this->SatisfactionScore;
}

void Citizen::increaseSatisfaction(double increase){
  this->SatisfactionScore += increase;
}

void Citizen::decreaseSatisfaction(double decrease){
  this->SatisfactionScore -= decrease;
}