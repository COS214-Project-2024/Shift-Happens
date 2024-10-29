#ifndef BOYBUILDER_H
#define BOYBUILDER_H

#include "CitizenBuilder.h"
#include "Boy.h"

#include <memory>

class BoyBuilder : public CitizenBuilder {
	private:
		std::shared_ptr<Boy> Boy;
	public:
		void addGender();
		void addType();
		void addStatus();
		std::shared_ptr<Citizen> getCitizen();
};

#endif
