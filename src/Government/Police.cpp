#include "Police.h"
#include <limits>
#include <memory>

void Police::increaseBudget(){
  std::string answer;
  double amount;

  std::cout << "Enter the amount you would like to increase the police service budget with" << std::endl;

  while(!(std::cin >> amount)){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a valid number (integer or decimal): ";
  }

  InfraStructureCondition->increaseBudget(amount);
}

void Police::decreaseBudget(){
  std::string answer;
  double amount;

  std::cout << "Enter the amount you would like to decrease the police service budget with" << std::endl;

  while(!(std::cin >> amount)){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a valid number (integer or decimal): ";
  }

  InfraStructureCondition->descreaseBudget(amount);
}

void Police::setPublicServiceState(std::shared_ptr<PublicServiceState> newState){
  this->InfraStructureCondition.reset();
  this->InfraStructureCondition = newState;

  this->notify();
}

std::shared_ptr<PublicServiceState> Police::getState(){
  return InfraStructureCondition;
}

std::string Police::getTypeOfPublicService(){
  return "Police";
}