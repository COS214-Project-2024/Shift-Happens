#include "Materials.h"

Materials::Materials(std::string description, double cost, int quantity) {
	this->description = description;
	this->cost = cost;
	this->quantity = quantity;
}