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
		std::vector<Building*> buildings; //track all buildings in the game
		std::vector<Citizen*> citizens; //track all citizens in the game
		double citySatisfactionScore; //this score will be assigned by the getAverageCitizenSatisfaction function
		double employmentRate; //this score will be assigned by the getEmploymentRates function
	
	public:
		Statistics(){
			citySatisfactionScore = 0;
			employmentRate = 0;
		};

		void addBuilding(Building *building){ 																			//this needs to work with the constructors for all the buildings
			buildings.push_back(building);
		}; 

		void removeBuilding(Building *building){                                                                        //this needs to work with the destructors for all the buildings
			for(int i = 0; i < buildings.size(); i++){
				if(buildings[i] == building){
					buildings.erase(buildings.begin() + i);
				}
			}
		}; 

		void addCitizen(Citizen *citizen){ 																				//this needs to work with the constructors for all the citizens
			citizens.push_back(citizen);
		};

		void removeCitizen(Citizen *citizen){																			//this needs to work with the destructors for all the citizens
			for(int i = 0; i < citizens.size(); i++){
				if(citizens[i] == citizen){
					citizens.erase(citizens.begin() + i);
				}
			}
		};

		double getAverageCitizenSatisfaction(Citizen* average){ //should calculate the average satisfaction score for the city and assign to citySatisfactionScore
			double sum = 0;
			for(int i = 0; i < citizens.size(); i++){
				sum += citizens[i]->getSatisfactionScore();
			}
			double averageScore = sum/citizens.size();
			return averageScore;
		};

		void getEmploymentRates(Government* var){ //either use the citizens vector and count the number of citizens employed vs the number of citizens not employed or get the government to collect this data and just display it here

		}; //should calculate the employment rates for the city and assign to employment rate
		
		void displayStatistics(){
			std::cout << "City Satisfaction Score: " << citySatisfactionScore << std::endl;
			std::cout << "Employment Rate: " << employmentRate << std::endl;
		}; //should call the displays for all buildings in the model
		// void getBuilding(int id); // function necessity to be determined
	};


#endif

//add a statistics pointer in every building and citizen object