#include <memory>
#include <string>
#include <iostream>
#include <gtest/gtest.h>


//Game
#include "../game/Game.h"

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

using namespace std;

/*
TEST(ExampleTest, SimpleTest) { //mock test to check if Gtest is working
    EXPECT_EQ(1 + 1, 2);
}
*/


TEST(PolicyTest, CanCreateEducationService) {
    // Test the creation of Education service
    shared_ptr<Education> education = make_shared<Education>();
    EXPECT_EQ(education->getTypeOfPublicService(), "Education")
        << "Expected the type of public service to be 'Education'.";
}

TEST(PolicyTest, CanCreateHealthCareService) {
    // Test the creation of HealthCare service
    shared_ptr<HealthCare> healthcare = make_shared<HealthCare>();
    EXPECT_EQ(healthcare->getTypeOfPublicService(), "Health Care")
        << "Expected the type of public service to be 'Health Care'.";
}

TEST(PolicyTest, CanCreatePoliceService) {
    // Test the creation of Police service
    shared_ptr<Police> police = make_shared<Police>();
    EXPECT_EQ(police->getTypeOfPublicService(), "Police")
        << "Expected the type of public service to be 'Police'.";
}

TEST(PolicyTest, CanCreateBoostEducationPolicy) {
    // Test creation of Boost Education Policy
    shared_ptr<Education> education = make_shared<Education>();
    shared_ptr<Policy> boostEducation = make_shared<BoostEducationPolicy>(education);
    EXPECT_EQ(boostEducation->getPolicyType(), "Boost Education Policy")
        << "Expected the policy type to be 'Boost Education Policy'.";
    
    // Test the current states of education
    EXPECT_EQ(education->getState()->getType(), "Outdated Services")
        << "Expected the education state to be 'Outdated Services'.";
}

TEST(PolicyTest, CanCreateBoostHealthCarePolicy) {
    // Test creation of Boost HealthCare Policy
    shared_ptr<HealthCare> healthcare = make_shared<HealthCare>();
    shared_ptr<Policy> boostHealthCare = make_shared<BoostHealthCarePolicy>(healthcare);
    EXPECT_EQ(boostHealthCare->getPolicyType(), "Boost Healthcare Policy")
        << "Expected the policy type to be 'Boost Healthcare Policy'.";
    
    // Test the current states of healthcare
    EXPECT_EQ(healthcare->getState()->getType(), "Outdated Services")
        << "Expected the healthcare state to be 'Outdated Services'.";
}

TEST(PolicyTest, CanCreateBoostPolicePolicy) {
    // Test creation of Boost Police Policy
    shared_ptr<Police> police = make_shared<Police>();
    shared_ptr<Policy> boostPolice = make_shared<BoostPolicePolicy>(police);
    EXPECT_EQ(boostPolice->getPolicyType(), "Boost Police Policy")
        << "Expected the policy type to be 'Boost Police Policy'.";
    
    // Test the current states of police
    EXPECT_EQ(police->getState()->getType(), "Outdated Services")
        << "Expected the police state to be 'Outdated Services'.";
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}