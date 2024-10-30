#include "Solar.h"

Solar::Solar(shared_ptr<Building>) : Upgrade(building) {
    type = "Solar";
}

int Solar::getElectricityDemand() {
    return 0; // Set electricity demand to 0
}
void Solar::print() {
    //prints the building's attributes with the 0 electricity demand and upgrade type
    cout<<"Building Attributes:"<<endl;
    cout<<"Width: "<<building->getWidth()<<", Length: "<<building->getLength()<<endl;
    cout<<"Position: ("<<building->getXPos()<<", "<<building->getYPos()<<")"<<endl;
    cout<<"Type: "<<building->getType()<<", Variant: "<<building->getVariant()<<endl;
    cout<<"Upgrade Type: "<<type<<endl;
    cout<<"Construction Price: "<<building->getConstructionPrice()<<endl;
    cout<<"Waste Produced: "<<building->getWasteProduced()<<", Sewage Produced: "<<building->getSewageProduced()<<endl;
    cout<<"Electricity Demand: "<<0<<", Water Demand: "<<building->getWaterDemand()<<endl;
    cout<<"Water Demand: "<<building->getWaterDemand()<<endl;



}