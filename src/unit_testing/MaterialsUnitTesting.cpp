#include <memory>
#include <string>
#include <iostream>
#include <gtest/gtest.h>


//Game
#include "../game/Game.h"

//Materials
#include"../buildings/Materials.h"

//BuildingFactories
#include "../buildingFactories/ResidentialBuildingFactory.h"
#include "../buildingFactories/CommercialBuildingFactory.h"
#include "../buildingFactories/IndustrialBuildingFactory.h"
#include "../buildingFactories/UtilityBuildingFactory.h"
#include "../buildingFactories/LandmarkBuildingFactory.h"
#include "../buildingFactories/InfrastructureFactory.h"
#include "../buildingFactories/TransportBuildingFactory.h" // Include TransportBuildingFactory

#include "../buildingFactories/BuildingFactory.h"

//Buildings
#include "../buildings/Building.h"

#include "../buildings/residential/House.h"
#include "../buildings/residential/TownHouse.h"
#include "../buildings/residential/Estate.h"
#include "../buildings/residential/Apartment.h"

#include "../buildings/commercial/Store.h"
#include "../buildings/commercial/Office.h"
#include "../buildings/commercial/Mall.h"

#include "../buildings/industrial/Factory.h"
#include "../buildings/industrial/Warehouse.h"
#include "../buildings/industrial/Manufacturer.h"

#include "../buildings/utility/PowerPlant.h"
#include "../buildings/utility/WaterSupply.h"
#include "../buildings/utility/SewagePlant.h"
#include "../buildings/utility/LandFill.h"

#include "../buildings/landmark/Monument.h"
#include "../buildings/landmark/Park.h"
#include "../buildings/landmark/CulturalCenter.h"

#include "../buildings/infrastructure/Road.h"
#include "../buildings/infrastructure/Railway.h"

#include "../buildings/transport/Airport.h"
#include "../buildings/transport/BusStation.h"
#include "../buildings/transport/TrainStation.h"


//Policies
#include "../Government/PublicServiceState.h"
#include "../Government/Standard.h"
#include "../Government/Outdated.h"
#include "../Government/Modern.h"
#include "../Government/PublicServices.h"
#include "../Government/CitySubject.h"
#include "../citizens/CitizenObserver.h"
#include "../Government/Education.h"
#include "../Government/HealthCare.h"
#include "../Government/Police.h"
#include "../Government/BoostEducationPolicy.h"
#include "../Government/BoostHealthCarePolicy.h"
#include "../Government/BoostPolicePolicy.h"
#include "../Government/Policy.h"

//#include "../Government/UnderPopulated.h"
//#include "../Government/Normal.h"  
//#include "../Government/Economy.h"
//#include "../Government/Government.h"
//#include "../Government/StandardTax.h"
//#include "../Government/LowTax.h"
//#include "../Government/HighTax.h"
//#include"../buildings/Materials.h"

using namespace std;
//testing constructor w sensible values
TEST(MaterialsTest, ConstructorTest) {
string desc = "Wood";
double cost = 50.0;
int quantity = 100;
//create
Materials mat(desc,cost,quantity);
//check if can be created without exceptions
EXPECT_NO_THROW(Materials(desc, cost, quantity));
}
//Testing constructor with garbade values
TEST(MaterialsTest,ConstructorInvalidTest){
    string desc = "";
    double cost = -100;
    int quantity = -5;
    //create
    
    //expecting it to throw error for nonsesne values
    // Expecting the constructor to throw an exception for nonsensical values
    EXPECT_THROW({
        Materials mat(desc, cost, quantity);
    }, std::invalid_argument); // Specify the type of exception to expect
}