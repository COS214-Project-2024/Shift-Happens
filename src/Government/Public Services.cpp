#include "Public Services.h"
#include <limits>

void Public_Services::DelegateFunds(){
  std::string answer;
  double amount;

  std::cout << "Would you like to increase or decrease the public services funds? " << std::endl;
  std::cin >> answer;

  if(answer == "Increase" || answer == "increase"){
    std::cout << "Enter the amount you would like to increase the public service budget with" << std::endl;

    while(!(std::cin >> amount)){
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a valid number (integer or decimal): ";
    }

    InfraStructureCondition->increaseBudget(amount);

  } else if(answer == "Decrease" || answer == "decrease"){
    std::cout << "Enter the amount you would like to decrease the public service budget with" << std::endl;

    while(!(std::cin >> amount)){
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a valid number (integer or decimal): ";
    }

    InfraStructureCondition->descreaseBudget(amount);
  } else {
    bool done = false;
		while (done != true)
		{
			std::cout << "Input did not match the expected increase or decrease input. Try again." << std::endl;
			std::cout << "Would you like to increase or decrease the public services funds? " << std::endl;
			
      if(answer == "Increase" || answer == "increase"){
        std::cout << "Enter the amount you would like to increase the public service budget with" << std::endl;

        while(!(std::cin >> amount)){
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Invalid input. Please enter a valid number (integer or decimal): ";
        }

        InfraStructureCondition->increaseBudget(amount);
        done = true;

      } else if(answer == "Decrease" || answer == "decrease"){
        std::cout << "Enter the amount you would like to decrease the public service budget with" << std::endl;

        while(!(std::cin >> amount)){
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Invalid input. Please enter a valid number (integer or decimal): ";
        }

        InfraStructureCondition->descreaseBudget(amount);
        done = true;
      }
		}
  }
}

void Public_Services::setPublicServiceState(PublicServiceState* newState){
  delete this->InfraStructureCondition;
  this->InfraStructureCondition = newState;

  this->notify();
}

PublicServiceState* Public_Services::getState(){
  return InfraStructureCondition;
}