#include <iostream>
#include <string>
#include <vector>
#ifndef MATERIALS_H
#define MATERIALS_H

	class Materials {
		std::string description;
		double cost;
		int quantity;

	public:
		Materials(std::string description, double cost, int quantity);};

#endif
