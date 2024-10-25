#ifndef BOYBUILDER_H
#define BOYBUILDER_H

#include "CitizenBuilder.h"
#include "Boy.h"

	class BoyBuilder : public CitizenBuilder {
		private:
		Boy* Boy;
	public:
		void addGender();

		void addType();

		void addStatus();

		Citizen* getCitizen();
	};

#endif
