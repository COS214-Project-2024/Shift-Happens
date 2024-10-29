#include "Road.h"
#include <iostream>

Road::Road(int id)
:Infrastructure("Road", id)
{
	
}

Road::~Road()
{
	
}

void Road::print()
{
	cout << "Road" << endl;
}