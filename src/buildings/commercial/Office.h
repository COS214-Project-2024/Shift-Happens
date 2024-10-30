#ifndef OFFICE_H
#define OFFICE_H

#include "CommercialBuilding.h"

class Office : public CommercialBuilding
{
private:
	/* data */
public:
	Office(int id);
	~Office();

	void print();
};



#endif
