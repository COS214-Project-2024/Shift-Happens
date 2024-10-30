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

//Policies
#include "Government/PublicServiceState.h"
#include "Government/Standard.h"
#include "Government/Outdated.h"
#include "Government/Modern.h"
#include "Government/PublicServices.h"
#include "Government/CitySubject.h"
#include "citizens/CitizenObserver.h"
#include "Government/Education.h"
#include "Government/HealthCare.h"
#include "Government/Police.h"
#include "Government/BoostEducationPolicy.h"
#include "Government/BoostHealthCarePolicy.h"
#include "Government/BoostPolicePolicy.h"
#include "Government/Policy.h"

using namespace std;

void demo() {
    Game game;
    game.run();
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

void testPolicies(){
    cout<<"Testing Policies..."<<endl;

    cout<<"Creating Public Services..."<<endl;
    shared_ptr<Education> education = make_shared<Education>();
    cout<<education->getTypeOfPublicService()<<" successfully created..."<<endl;
    
    shared_ptr<HealthCare> healthcare = make_shared<HealthCare>();
    cout<<healthcare->getTypeOfPublicService()<<" successfully created..."<<endl;
    
    shared_ptr<Police> police = make_shared<Police>();
    cout<<police->getTypeOfPublicService()<<" successfully created..."<<endl;

    cout<<"Creating Policies..."<<endl;
    shared_ptr<Policy> boostEducation = make_shared<BoostEducationPolicy>(education);
    cout<<"Current policy type: "<<boostEducation->getPolicyType()<<endl;
    cout<<"Current state of education: "<<education->getState()->getType()<<endl;

    cout<<"Executing Boost Education Policy..."<<endl;
    //start with insuficient funds
    boostEducation->executePolicy(500);
    cout<<"Current state of education: "<<education->getState()->getType()<<endl;
    boostEducation->executePolicy(1000);
    cout<<"Current state of education: "<<education->getState()->getType()<<endl;

        //start with insuficient funds
    boostEducation->executePolicy(500);
    cout<<"Current state of education: "<<education->getState()->getType()<<endl;
    boostEducation->executePolicy(1000);
    cout<<"Current state of education: "<<education->getState()->getType()<<endl;

        //start with insuficient funds
    boostEducation->executePolicy(500);
    cout<<"Current state of education: "<<education->getState()->getType()<<endl;
    boostEducation->executePolicy(1000);
    cout<<"Current state of education: "<<education->getState()->getType()<<endl;


    shared_ptr<Policy> boostHealthCare = make_shared<BoostHealthCarePolicy>(healthcare);
    cout<<"Current policy type: "<<boostHealthCare->getPolicyType()<<endl;
    cout<<"Current state of healthcare: "<<healthcare->getState()->getType()<<endl;

    cout<<"Executing Boost HealthCare Policy..."<<endl;
    //start with insuficient funds
    boostHealthCare->executePolicy(500);
    cout<<"Current state of healthcare: "<<healthcare->getState()->getType()<<endl;
    boostHealthCare->executePolicy(1000);
    cout<<"Current state of healthcare: "<<healthcare->getState()->getType()<<endl;

    //start with insuficient funds
    boostHealthCare->executePolicy(500);
    cout<<"Current state of healthcare: "<<healthcare->getState()->getType()<<endl;
    boostHealthCare->executePolicy(1000);
    cout<<"Current state of healthcare: "<<healthcare->getState()->getType()<<endl;

        //start with insuficient funds
    boostHealthCare->executePolicy(500);
    cout<<"Current state of healthcare: "<<healthcare->getState()->getType()<<endl;
    boostHealthCare->executePolicy(1000);
    cout<<"Current state of healthcare: "<<healthcare->getState()->getType()<<endl;

    shared_ptr<Policy> boostPolice = make_shared<BoostPolicePolicy>(police);
    cout<<"Current policy type: "<<boostPolice->getPolicyType()<<endl;
    cout<<"Current state of police: "<<police->getState()->getType()<<endl;

    cout<<"Executing Boost Police Policy..."<<endl;
    //start with insuficient funds
    boostPolice->executePolicy(500);
    cout<<"Current state of police: "<<police->getState()->getType()<<endl;
    boostPolice->executePolicy(1000);
    cout<<"Current state of police: "<<police->getState()->getType()<<endl;

        //start with insuficient funds
    boostPolice->executePolicy(500);
    cout<<"Current state of police: "<<police->getState()->getType()<<endl;
    boostPolice->executePolicy(1000);
    cout<<"Current state of police: "<<police->getState()->getType()<<endl;

        //start with insuficient funds
    boostPolice->executePolicy(500);
    cout<<"Current state of police: "<<police->getState()->getType()<<endl;
    boostPolice->executePolicy(1000);
    cout<<"Current state of police: "<<police->getState()->getType()<<endl;

        //start with insuficient funds
    boostPolice->executePolicy(500);
    cout<<"Current state of police: "<<police->getState()->getType()<<endl;
    boostPolice->executePolicy(1000);
    cout<<"Current state of police: "<<police->getState()->getType()<<endl;
}

int main() {
    //demo();
    //testBuildingFactory();
    testPolicies();
    return 0;
}