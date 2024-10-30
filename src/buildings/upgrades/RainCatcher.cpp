#include "RainCatcher.h"

RainCatcher::RainCatcher(shared_ptr<Building> building) : Upgrade(building) {}

int RainCatcher::getWaterDemand() {
    return 0; // Set water demand to 0
}

void RainCatcher::print() {
    //prints the building's attributes with the 0 water demand and upgrade type
    cout<<"Building Attributes:"<<endl;
    cout<<"Width: "<<building->getWidth()<<", Length: "<<building->getLength()<<endl;
    cout<<"Position: ("<<building->getXPos()<<", "<<building->getYPos()<<")"<<endl;
    cout<<"Type: "<<building->getType()<<", Variant: "<<building->getVariant()<<endl;
    cout<<"Upgrade Type: RainCatcher"<<endl;
    cout<<"Construction Price: "<<building->getConstructionPrice()<<endl;
    cout<<"Waste Produced: "<<building->getWasteProduced()<<", Sewage Produced: "<<building->getSewageProduced()<<endl;
    cout<<"Electricity Demand: "<<building->getElectricityDemand()<<", Water Demand: "<<0<<endl;
    cout<<"Water Demand: "<<0<<endl;
}