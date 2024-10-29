#ifndef TAX_H
#define TAX_H

#include "../Government/Government.h"

#include <iostream>

class Tax {
	private:
	
	protected:
		std::shared_ptr<Government> government;
		double RunningRate;
		double RunningRateBusiness;

	public:
		// personal tax
		virtual void higher(double increase) = 0;
		virtual void lower(double decrease) = 0;
		virtual std::string getType()=0;
		double getRate();
		// business tax
		virtual void higherBusiness(double increase)=0;
		virtual void lowerBusiness(double decrease)=0;
		double getBusinessRate();
};

#endif
