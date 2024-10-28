#include "Railway.h"
#include <iostream>
Railway::Railway(int id)
:Infrastructure("Railway", id)
{
	
}

Railway::~Railway()
{
	
}

void Railway::print()
{
	cout << "Railway" << endl;
}


