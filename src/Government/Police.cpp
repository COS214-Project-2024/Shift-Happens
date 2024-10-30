#include "Police.h"
#include <limits>
#include <memory>


Police::Police(){
  InfraStructureCondition = std::make_shared<Outdated>();  // Initial Standard state for police
}

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

  InfraStructureCondition->decreaseBudget(amount);
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