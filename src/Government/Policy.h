#ifndef POLICY_H
#define POLICY_H

class Policy {
		std::string PolicyName;
	public:
		virtual void executePolicy() = 0;
};

#endif
