#include "Garden.h"

Garden::Garden(shared_ptr<Building> building) : Upgrade(building) {}

int Garden::getSewageProduced() {
    return 0; // Set sewage produced to 0
}
void Garden::print() {
    //prints the building's attributes with the 0 sewage produced and upgrade type
    cout<<"Building Attributes:"<<endl;
    cout<<"Width: "<<building->getWidth()<<", Length: "<<building->getLength()<<endl;
    cout<<"Position: ("<<building->getXPos()<<", "<<building->getYPos()<<")"<<endl;
    cout<<"Type: "<<building->getType()<<", Variant: "<<building->getVariant()<<endl;
    cout<<"Upgrade Type: Garden"<<endl;
    cout<<"Construction Price: "<<building->getConstructionPrice()<<endl;
    cout<<"Waste Produced: "<<building->getWasteProduced()<<", Sewage Produced: "<<0<<endl;
    cout<<"Electricity Demand: "<<building->getElectricityDemand()<<", Water Demand: "<<building->getWaterDemand()<<endl;
    cout<<"Water Demand: "<<building->getWaterDemand()<<endl;
}