#ifndef HOUSEPLANNINGPOLICY_H
#define HOUSEPLANNINGPOLICY_H

#include "Policy.h";
/*
 - Will increase population if there is a under populated community by doing:
   1. improve education, public servies
	 2. improve healthcare
	 3. 
*/

class HousePlanningPolicy : public Policy {


	public:
		void executePolicy();
};

#endif
