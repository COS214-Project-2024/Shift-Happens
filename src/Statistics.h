#ifndef STATISTICS_H
#define STATISTICS_H
#include <iostream>
#include <vector>
#include <string>
#include "Materials.h"
#include "Building.h"
#include "Citizen.h"
#include "Government.h"
#include "buildings/utility/PowerPlant.h"
#include "buildings/utility/WaterSupply.h"


	class Statistics {
	private:
		std::vector<Building*> buildings; //track all buildings in the game
		std::vector<Citizen*> citizens; //track all citizens in the game
		std::vector<Materials*> materials; //track all materials in the game
	
		double powerConsumption; //75% of supply
		double waterConsumption; //60% of supply
		double waterSupply; //this score will be assigned by the getWaterSupply function
		double electricitySupply; //this score will be assigned by the getElectricitySupply function

		double citySatisfactionScore; //this score will be assigned by the getAverageCitizenSatisfaction function
		double employmentRate; //this score will be assigned by the getEmploymentRates function
		int numberOfBuildings;
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
		
		void getUtilityStatistics(PowerPlant *powerPlant, WaterSupply *waterSupply)
		{
			// get the power consumption, water consumption, water supply, and electricity supply from the government object
			// assign these values to the powerConsumption, waterConsumption, waterSupply, and electricitySupply variables in the statistics object
			electricitySupply = powerPlant->getElectricityProduction();
			this->waterSupply = waterSupply->getWaterSupply();
			waterConsumption = 0.6 * this->waterSupply;
			powerConsumption = 0.75 * electricitySupply;
		};

		void displayStatistics(){
			std::cout << "City Satisfaction Score: " << citySatisfactionScore << std::endl;
			std::cout << "Employment Rate: " << employmentRate << std::endl;
			std::cout << "Number of Buildings: " << buildings.size() << std::endl;
			std::cout << "Number of Citizens: " << citizens.size() << std::endl;
			std::cout << "Power Consumption: " << powerConsumption << std::endl;
			std::cout << "Water Consumption: " << waterConsumption << std::endl;
			std::cout << "Water Supply: " << waterSupply << std::endl;
			std::cout << "Electricity Supply: " << electricitySupply << std::endl;

		}; //should call the displays for all buildings in the model

	};

	


#endif

//add a statistics pointer in every building and citizen object