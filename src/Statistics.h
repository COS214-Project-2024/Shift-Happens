#ifndef STATISTICS_H
#define STATISTICS_H
#include <iostream>
#include <vector>
#include <string>
#include "Materials.h"
#include "Building.h"
#include "Citizen.h"
#include "Government.h"



	class Statistics {
	private:
		std::vector<Building*> buildings; //track all building in the game
		double citySatisfactionScore; //this score will be assigned by the getAverageCitizenSatisfaction function
		double employmentRate; //this score will be assigned by the getEmploymentRates function

	public:
		Statistics(std::string description, double cost, int quantity);
		void addBuilding(Building *building); //this needs to work with the constructors for all the buildings
		void removeBuilding(Building *building); //this needs to work with the destructors for all the buildings
		double getAverageCitizenSatisfaction(Citizen* average);
		void getEmploymentRates(Government* var); //should calculate the employment rates for the city and assign to employment rate
		void displayStatistics(); //should call the displays for all buildings in the model
		// void getBuilding(int id); // function necessity to be determined
	};


#endif

//add a statistics pointer in every building and citizen object