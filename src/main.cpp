#include <memory>
#include <string>
#include <iostream>
#include <cstdlib>
//Game
#include "game/Game.h"

//BuildingFactories
#include "buildingFactories/ResidentialBuildingFactory.h"
#include "buildingFactories/CommercialBuildingFactory.h"
#include "buildingFactories/IndustrialBuildingFactory.h"
#include "buildingFactories/UtilityBuildingFactory.h"
#include "buildingFactories/LandmarkBuildingFactory.h"
#include "buildingFactories/InfrastructureFactory.h"
#include "buildingFactories/TransportBuildingFactory.h" // Include TransportBuildingFactory

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

#include "buildings/transport/Airport.h"
#include "buildings/transport/BusStation.h"
#include "buildings/transport/TrainStation.h"

using namespace std;

void demo() {
   
    try{
        Game game;
        game.run();
    } catch (char const* msg) {
        cout << msg << endl;
    }
}

void testBuildingFactory() {
    cout << "Testing Building Factory" << endl;
    cout << "Creating Building Factories of each type" << endl;
    shared_ptr<BuildingFactory> resFactory = make_shared<ResidentialBuildingFactory>(1);
    shared_ptr<BuildingFactory> comFactory = make_shared<CommercialBuildingFactory>(2);
    shared_ptr<BuildingFactory> indFactory = make_shared<IndustrialBuildingFactory>(3);
    shared_ptr<BuildingFactory> utiFactory = make_shared<UtilityBuildingFactory>(4);
    shared_ptr<BuildingFactory> landFactory = make_shared<LandmarkBuildingFactory>(5);
    shared_ptr<BuildingFactory> infraFactory = make_shared<InfrastructureFactory>(6);
    shared_ptr<BuildingFactory> transFactory = make_shared<TransportBuildingFactory>(7); // Create TransportBuildingFactory

    cout << "Creating Buildings" << endl;
    resFactory->createBuilding("House");
    resFactory->createBuilding("TownHouse");
    resFactory->createBuilding("Estate");
    resFactory->createBuilding("Apartment");

    comFactory->createBuilding("Store");
    comFactory->createBuilding("Office");
    comFactory->createBuilding("Mall");

    indFactory->createBuilding("Factory");
    indFactory->createBuilding("Warehouse");
    indFactory->createBuilding("Manufacturer");

    utiFactory->createBuilding("PowerPlant");
    utiFactory->createBuilding("WaterSupply");
    utiFactory->createBuilding("SewagePlant");
    utiFactory->createBuilding("LandFill");

    landFactory->createBuilding("Park");
    landFactory->createBuilding("Monument");
    landFactory->createBuilding("CulturalCenter");

    infraFactory->createBuilding("Road");
    infraFactory->createBuilding("Railway");

    transFactory->createBuilding("Airport"); // Create transport buildings
    transFactory->createBuilding("BusStation");
    transFactory->createBuilding("TrainStation");

    // Print buildings
    cout << "Printing Buildings" << endl;
    resFactory->print();
    comFactory->print();
    indFactory->print();
    utiFactory->print();
    landFactory->print();
    infraFactory->print();
    transFactory->print(); // Print transport buildings
}

void testMap() {
    cout << "Testing Map" << endl;

    // Get the singleton instance of the Map
    Map& map = Map::getInstance();

    // Build some buildings on the map
    map.build("House", "Residential", 0, 0);
    map.build("Store", "Commercial", 1, 1);
    map.build("Factory", "Industrial", 2, 2);
    map.build("PowerPlant", "Utility", 3, 3);
    map.build("Park", "Landmark", 4, 4);
    map.build("Road", "Infrastructure", 5, 5);
    map.build("Airport", "Transport", 6, 6);

    // Print the map
    map.print();
}

int main() {
    demo();
    //testBuildingFactory();
    //testMap();
    return 0;
}