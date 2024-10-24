#ifndef GOVERNMENT_H
#define GOVERNMENT_H

namespace Building_State {
	class Government : Building_State::CitySubject {

	private:
		Tax* TaxState;
		vector<Building_State::Policy*> PolicyState;

	public:
		void setTaxLower();

		void setTaxHigher();

		void addPolicy(Policy* newPolicy);

		void executePolicy();
	};
}

#endif
