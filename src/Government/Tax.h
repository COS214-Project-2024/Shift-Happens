#ifndef TAX_H
#define TAX_H

#include "Government.h"

#include <iostream>

class Tax {
	private:
	
	protected:
		Government* government;
		double RunningRate;

	public:
		virtual void higher(double increase) = 0;
		virtual void lower(double decrease) = 0;
		virtual std::string getType()=0;
		double getRate();
};

#endif
