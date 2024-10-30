#ifndef STORE_H
#define STORE_H
#include "CommercialBuilding.h"
class Store : public CommercialBuilding
{

public:
	Store(int id);
	~Store();

	void print();
private:


};

#endif
