#include "Education.h"
#include <limits>

Education::Education(){
  InfraStructureCondition = nullptr;  // Initital Standard budget for education
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

  InfraStructureCondition->descreaseBudget(amount);
}

void Education::setPublicServiceState(PublicServiceState* newState){
  delete this->InfraStructureCondition;
  this->InfraStructureCondition = newState;

  this->notify();
}

PublicServiceState* Education::getState(){
  return InfraStructureCondition;
}

std::string Education::getTypeOfPublicService(){
  return "Education";
}