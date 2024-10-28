#include <memory>
#include <string>
#include <iostream>

//Game
#include "game/Game.h"

//BuildingFactories
#include "buildingFactories/ResidentialBuildingFactory.h"
#include "buildingFactories/CommercialBuildingFactory.h"
#include "buildingFactories/IndustrialBuildingFactory.h"
#include "buildingFactories/UtilityBuildingFactory.h"
#include "buildingFactories/LandmarkBuildingFactory.h"
#include "buildingFactories/InfrastructureFactory.h"

#include "buildingFactories/BuildingFactory.h"

//Buildings
#include "buildings/Building.h"

#include "buildings/residential/House.h"
#include "buildings/residential/TownHouse.h"
#include "buildings/residential/Estate.h"
#include "buildings/residential/Apartment.h"

#include "buildings/commercial/Store.h"
#include "buildings/commercial/Office.h"
#include "buildings/commercial/Mall.h"

#include "buildings/industrial/Factory.h"
#include "buildings/industrial/Warehouse.h"
#include "buildings/industrial/Manufacturer.h"

#include "buildings/utility/PowerPlant.h"
#include "buildings/utility/WaterSupply.h"
#include "buildings/utility/SewagePlant.h"
#include "buildings/utility/LandFill.h"

#include "buildings/landmark/Monument.h"
#include "buildings/landmark/Park.h"
#include "buildings/landmark/CulturalCenter.h"

#include "buildings/infrastructure/Road.h"
#include "buildings/infrastructure/Railway.h"






using namespace std;

void demo() {
    Game game;
    game.run();
}

void testBuildingFactory() {
    cout<<"Testing Building Factory"<<endl;
    cout<<"Creating Building Factories of each type"<<endl;
    shared_ptr<BuildingFactory> resFactory = make_shared<ResidentialBuildingFactory>(1);
    shared_ptr<BuildingFactory> comFactory = make_shared<CommercialBuildingFactory>(2);
    shared_ptr<BuildingFactory> indFactory = make_shared<IndustrialBuildingFactory>(3);
    shared_ptr<BuildingFactory> utiFactory = make_shared<UtilityBuildingFactory>(4);
    shared_ptr<BuildingFactory> landFactory = make_shared<LandmarkBuildingFactory>(5);
    shared_ptr<BuildingFactory> infraFactory = make_shared<InfrastructureFactory>(6);


    cout<<"Creating Buildings using the factories"<<endl;

    cout<<"Creating Residential Buildings"<<endl;
    shared_ptr<Building> house = resFactory->createBuilding("House");
    shared_ptr<Building> townHouse = resFactory->createBuilding("TownHouse");
    shared_ptr<Building> estate = resFactory->createBuilding("Estate");
    shared_ptr<Building> apartment = resFactory->createBuilding("Apartment");

    cout<<"Creating Commercial Buildings"<<endl;
    shared_ptr<Building> store = comFactory->createBuilding("Store");
    shared_ptr<Building> office = comFactory->createBuilding("Office");
    shared_ptr<Building> mall = comFactory->createBuilding("Mall");

    cout<<"Creating Industrial Buildings"<<endl;
    shared_ptr<Building> factory = indFactory->createBuilding("Factory");
    shared_ptr<Building> warehouse = indFactory->createBuilding("Warehouse");
    shared_ptr<Building> manufacturer = indFactory->createBuilding("Manufacturer");

    cout<<"Creating Utility Buildings"<<endl;
    shared_ptr<Building> powerPlant = utiFactory->createBuilding("PowerPlant");
    shared_ptr<Building> waterSupply = utiFactory->createBuilding("WaterSupply");
    shared_ptr<Building> sewagePlant = utiFactory->createBuilding("SewagePlant");
    shared_ptr<Building> landFill = utiFactory->createBuilding("LandFill");

    cout<<"Creating Landmark Buildings"<<endl;
    shared_ptr<BuildingFactory> landFactory = make_shared<LandmarkBuildingFactory>(5);
    shared_ptr<Building> landmark = landFactory->createBuilding("Landmark");
    shared_ptr<Building> park = landFactory->createBuilding("Park");
    shared_ptr<Building> culturalCenter = landFactory->createBuilding("CulturalCenter");

    cout<<"Creating Infrastructure Buildings"<<endl;
    shared_ptr<Infrastructure> road = infraFactory->createBuilding("Road");
    shared_ptr<Infrastructure> railway = infraFactory->createBuilding("Railway");

    



}
int main() {
    //demo();
    testBuildingFactory();
    return 0;
}