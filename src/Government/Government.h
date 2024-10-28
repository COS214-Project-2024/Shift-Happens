#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "Tax.h"
#include "CitySubject.h"
#include "Policy.h"

// Concrete subject in observer pattern
// Context in state pattern

/*
Government has tax rates and policies

*/ 

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
		std::vector<Policy*> getPolicies();
};

#endif
