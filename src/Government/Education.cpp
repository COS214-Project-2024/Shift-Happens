#include "Education.h"
#include <limits>

Education::Education(){
  InfraStructureCondition = std::make_shared<Outdated>();  // Initial Standard state for education

}

void Education::increaseBudget(){
  std::string answer;
  double amount;

  std::cout << "Enter the amount you would like to increase the education service budget with" << std::endl;

  while(!(std::cin >> amount)){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a valid number (integer or decimal): ";
  }

  InfraStructureCondition->increaseBudget(amount);
}

void Education::decreaseBudget(){
  std::string answer;
  double amount;

  std::cout << "Enter the amount you would like to decrease the education service budget with" << std::endl;

  while(!(std::cin >> amount)){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Please enter a valid number (integer or decimal): ";
  }

  InfraStructureCondition->decreaseBudget(amount);
}

void Education::setPublicServiceState(std::shared_ptr<PublicServiceState> newState){
  this->InfraStructureCondition.reset();
  this->InfraStructureCondition = newState;

  this->notify();
}

std::shared_ptr<PublicServiceState> Education::getState(){
  return InfraStructureCondition;
}

std::string Education::getTypeOfPublicService(){
  return "Education";
}