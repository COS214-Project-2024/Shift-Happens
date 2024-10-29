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
		double citySatisfactionScore;
		double employmentRate;
		
	public:
		Statistics(std::string description, double cost, int quantity);
		void addBuilding(Building *building);
		void removeBuilding(Building *building);
		void getBuilding(int id);
		void render();
		double getAverageCitizenSatisfaction(Citizen* average);
		void getEmploymentRates(Government* var); //should calculate the employment rates for the city and assign to employment rate
		void displayStatistics(); //should call the displays for all buildings in the model
	};


#endif
