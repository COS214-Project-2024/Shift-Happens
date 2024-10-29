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
	2. Oudated
*/

class Policy {
		std::string PolicyName;
	public:
		virtual void executePolicy() = 0;
};

#endif
