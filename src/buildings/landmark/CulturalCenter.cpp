#include "CulturalCenter.h"

CulturalCenter::CulturalCenter(int id)
    : LandMark(id, "CulturalCenter", 400, 20, 20, 20, 20, 50)
{
    
}

CulturalCenter::~CulturalCenter()
{
}

void CulturalCenter::print(){
    cout << "Cultural Center Attributes:" << endl;
    cout << "Construction Price: " << getConstructionPrice() << endl;
    cout << "Waste Produced: " << getWasteProduced() << endl;
    cout << "Sewage Produced: " << getSewageProduced() << endl;
    cout << "Electricity Demand: " << getElectricityDemand() << endl;
    cout << "Water Demand: " << getWaterDemand() << endl;
    LandMark::print(); // Call to LandMark's print function
}
