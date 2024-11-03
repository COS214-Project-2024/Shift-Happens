#ifndef TAXISTRATEGY_H
#define TAXISTRATEGY_H
#include "TransportationStrategy.h"
	class TaxiStrategy : public TransportationStrategy {

	private:
		int capacity;
		double baseFare;
		double aveSpeed;
		double costPerKm;

	public:
		double calculateCost(Map start, Map end);

		double calcDuration(Map start, Map end);

		string getDescription();
	};

#endif
