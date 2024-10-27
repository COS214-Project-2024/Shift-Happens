#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "Tax.h"
#include "CitySubject.h"
#include "Policy.h"

// Concrete subject in observer pattern
// Context in state pattern

class Government : public CitySubject {
	private:
		Tax* TaxState;
		std::vector<Policy*> PolicyState;

	public:
		void setTaxLower();
		void setTaxHigher();
		void addPolicy(Policy* newPolicy);
		void executePolicy();
		void setTaxState(Tax* tax);
		Tax* getTax();
};

#endif
