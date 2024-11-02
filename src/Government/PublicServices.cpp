#include "PublicServices.h"
#include <limits>

void Public_Services::DelegateFunds(){
  std::string answer;
  double amount;

  std::cout << "Would you like to increase or decrease the public services funds? " << std::endl;
  std::cin >> answer;

  if(answer == "Increase" || answer == "increase"){
    this->increaseBudget();
  } else if(answer == "Decrease" || answer == "decrease"){
    this->decreaseBudget();
  } else {
    bool done = false;
		while (done != true)
		{
			std::cout << "Input did not match the expected increase or decrease input. Try again." << std::endl;
			std::cout << "Would you like to increase or decrease the public services funds? " << std::endl;
			
      if(answer == "Increase" || answer == "increase"){
        this->increaseBudget();
        done = true;

      } else if(answer == "Decrease" || answer == "decrease"){
        this->decreaseBudget();
        done = true;
      }
		}
  }
}
