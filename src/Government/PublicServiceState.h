#ifndef PUBLICSERVICESTATE_H
#define PUBLICSERVICESTATE_H


class PublicServiceState {
	protected:
		double RunningBudget;
	public:
		virtual void increaseBudget(double increase) = 0;
		virtual void descreaseBudget(double decrease) = 0;
		virtual std::string getType() = 0;
};


#endif
