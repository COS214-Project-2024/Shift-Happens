#ifndef POLICY_H
#define POLICY_H

/*
	policies will solve goverment problems and use them according to current situations
	situations include:
	- over population
	- under population
	- unemployment
	- outdated public services

	1. Over population command:
	- It should decrease the population growth
	- Receiver: 
	2. Boost Education
	- Receiver: Education
	- Education can handle it by increasing their budget
	3. Boost Police
	- Receiver: Police
	- Police handles it by increasing their budget
	4. Boost Healthcare
	- Receiver: Heathcare
	- Healthcare can hanlde it by increasing their budget
*/

class Policy {
	public:
		virtual void executePolicy() = 0;
};

#endif
