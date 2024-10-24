#ifndef WOMANBUILDER_H
#define WOMANBUILDER_H

	class WomanBuilder : CitizenBuilder {

	public:
		Woman* Woman;

		void addGender();

		void addType();

		void addStatus();

		Citizen* getCitizen();
	};


#endif
