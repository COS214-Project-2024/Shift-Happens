#include "HealthCare.h"
#include <limits>
#include <memory>

void HealthCare::increaseBudget(){
  std::string answer;
  double amount;

  std::cout << "Enter the amount you would like to increase the health care service budget with" << std::endl;

  while(!(std::cin >> amount)){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a valid number (integer or decimal): ";
  }

  InfraStructureCondition->increaseBudget(amount);
}

void HealthCare::decreaseBudget(){
  std::string answer;
  double amount;

  std::cout << "Enter the amount you would like to decrease the health care service budget with" << std::endl;

  while(!(std::cin >> amount)){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a valid number (integer or decimal): ";
  }

  InfraStructureCondition->descreaseBudget(amount);
}

void HealthCare::setPublicServiceState(std::shared_ptr<PublicServiceState> newState){
  this->InfraStructureCondition.reset();
  this->InfraStructureCondition = newState;

  this->notify();
}

std::shared_ptr<PublicServiceState> HealthCare::getState(){
  return InfraStructureCondition;
}

std::string HealthCare::getTypeOfPublicService(){
  return "Health Care";
}