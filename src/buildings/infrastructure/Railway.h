#ifndef RAILWAY_H
#define RAILWAY_H

#include "Infrastructure.h"


using namespace std;
class Railway : public Infrastructure
{

private:
public:
	Railway(int id);
	~Railway();

	void print();
};

#endif
