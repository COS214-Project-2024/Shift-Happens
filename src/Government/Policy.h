#ifndef POLICY_H
#define POLICY_H

namespace Building_State {
	class Policy {


	public:
		virtual void handle() = 0;
	};
}

#endif
