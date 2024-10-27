#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H
#include "Building.h"
#include "Materials.h"
#include <vector>

using namespace std;
	class IndustrialBuilding : Building {

	private:
		int numberOfEmployees;
		int satisfactionScore;
		vector<Materials*> availableMaterials; //THIS WOULD STORE THE materials in the warehouse that were produced by the factory
	public:
		int getNumberOfEmployees();

		void setNumberOfEmployees(int numberOfEmployees);

		int getSatisfactionScore();

		void setSatisfactionScore(int satisfactionScore);
	};

#endif
