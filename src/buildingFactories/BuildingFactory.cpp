#include "BuildingFactory.h"

BuildingFactory::BuildingFactory(int id)
{
    this->id = id;
}
BuildingFactory::~BuildingFactory()
{
    throw "BuildingFactory::~BuildingFactory() not implemented";
    
}