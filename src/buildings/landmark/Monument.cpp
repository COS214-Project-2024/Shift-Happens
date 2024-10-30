#include "Monument.h"

Monument::Monument(int id)
    : LandMark(id, "Monument", 500, 20, 20, 20, 20, 50)
{
    
}

Monument::~Monument()
{
}

void Monument::print(){
    cout << "Monument Attributes:" << endl;
    cout << "Construction Price: " << getConstructionPrice() << endl;
    cout << "Waste Produced: " << getWasteProduced() << endl;
    cout << "Sewage Produced: " << getSewageProduced() << endl;
    cout << "Electricity Demand: " << getElectricityDemand() << endl;
    cout << "Water Demand: " << getWaterDemand() << endl;
    LandMark::print(); // Call to LandMark's print function
}