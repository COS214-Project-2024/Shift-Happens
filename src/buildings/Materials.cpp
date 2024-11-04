#include "Materials.h"

Materials::Materials(std::string description, double cost, int quantity) {
	//including validation tests for better unit testing
	// Check if description is empty
        if (description.empty()) {
            throw std::invalid_argument("Description cannot be empty.");
        }

        // Check if cost is valid (greater than 0)
        if (cost <= 0) {
            throw std::invalid_argument("Cost must be greater than 0.");
        }

        // Check if quantity is valid (greater than 0)
        if (quantity <= 0) {
            throw std::invalid_argument("Quantity must be greater than 0.");
        }

        // If all checks pass, initialize the member variables


	this->description = description;
	this->cost = cost;
	this->quantity = quantity;
}