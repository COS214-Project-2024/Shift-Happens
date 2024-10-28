#include <iostream>
#include <string>
#include <vector>
#ifndef MATERIALS_H
#define MATERIALS_H

	class Materials {
		std::string description;
		double cost;
		int quantity;
		std::vector<Materials*> components;
		int quantity;
		static double salesMade;

	public:
		Materials(std::string description, double cost, int quantity);};

#endif
