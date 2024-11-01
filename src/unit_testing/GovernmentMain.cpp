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

#include "../Government/UnderPopulated.h"
#include "../Government/Normal.h"  
#include "../Government/Economy.h"

using namespace std;

/*
TEST(ManBuilderTest, addTypeTest){
  std::shared_ptr<ManBuilder> manBuilder = std::make_shared<ManBuilder>();
  manBuilder->addType();
  std::shared_ptr<Citizen> man = manBuilder->getCitizen();
  ASSERT_NE(man, nullptr);
  EXPECT_EQ(man->getType(), "Man");
}
*/

// Population testing
TEST(UnderPopulatedTest, increasePopulation) {
  std::shared_ptr<UnderPopulated> underpopulated = make_shared<UnderPopulated>();
  std::shared_ptr<Economy> economy = make_shared<Economy>();
  underpopulated->setEconomy(economy);
  underpopulated->increasePopulation(500);
  EXPECT_EQ(underpopulated->getPopulationCount(), 500);
  EXPECT_EQ(economy->getState()->getType(), "Normal Population");
}

TEST(UnderPopulatedTest, increasePopulationWithoutTransition) {
  std::shared_ptr<UnderPopulated> underpopulated = make_shared<UnderPopulated>();
  std::shared_ptr<Economy> economy = make_shared<Economy>();
  underpopulated->setEconomy(economy);
  underpopulated->increasePopulation(200);
  EXPECT_EQ(underpopulated->getPopulationCount(), 200);
  EXPECT_EQ(economy->getState()->getType(), "Under Populated");
}

TEST(UnderPopulatedTest, decreasePopulation) {
  std::shared_ptr<UnderPopulated> underpopulated = make_shared<UnderPopulated>(1000);
  underpopulated->decreasePopulation(800);
  EXPECT_EQ(underpopulated->getPopulationCount(), 200);
}

TEST(UnderPopulatedTest, decreasePopulationBelowZero) {
  std::shared_ptr<UnderPopulated> underpopulated = make_shared<UnderPopulated>(200);
  underpopulated->decreasePopulation(800);
  EXPECT_EQ(underpopulated->getPopulationCount(), 0);
}

TEST(UnderPopulatedTest, getType) {
  std::shared_ptr<UnderPopulated> underPopulated = std::make_shared<UnderPopulated>();
  EXPECT_EQ(underPopulated->getType(), "Under Populated");
}


TEST(OverPopulatedTest, increasePopulation) {
  std::shared_ptr<OverPopulated> overpopulated = std::make_shared<OverPopulated>();
  overpopulated->increasePopulation(500);
  EXPECT_EQ(overpopulated->getPopulationCount(), 500);
}

TEST(OverPopulatedTest, decreasePopulationWithTransition) {
  std::shared_ptr<OverPopulated> overpopulated = std::make_shared<OverPopulated>(2500);
  std::shared_ptr<Economy> economy = std::make_shared<Economy>();
  overpopulated->setEconomy(economy);
  overpopulated->decreasePopulation(800);  // Should trigger transition to Normal
  EXPECT_EQ(overpopulated->getPopulationCount(), 1700);
  EXPECT_EQ(economy->getState()->getType(), "Normal Population");
}

TEST(OverPopulatedTest, decreasePopulationBelowLowCap) {
  std::shared_ptr<OverPopulated> overpopulated = std::make_shared<OverPopulated>(2100);
  overpopulated->decreasePopulation(1500);
  EXPECT_EQ(overpopulated->getPopulationCount(), 600);  // Above transition threshold
  EXPECT_EQ(overpopulated->getType(), "Over Populated");
}

TEST(OverPopulatedTest, getType) {
  std::shared_ptr<OverPopulated> overpopulated = std::make_shared<OverPopulated>();
  EXPECT_EQ(overpopulated->getType(), "Over Populated");
}

TEST(NormalTest, increasePopulationWithTransition) {
  std::shared_ptr<Normal> normal = std::make_shared<Normal>();
  std::shared_ptr<Economy> economy = std::make_shared<Economy>();
  normal->setEconomy(economy);
  normal->increasePopulation(2500);  // Should transition to OverPopulated
  EXPECT_EQ(normal->getPopulationCount(), 2500);
  EXPECT_EQ(economy->getState()->getType(), "Over Populated");
}

TEST(NormalTest, decreasePopulationWithTransition) {
  std::shared_ptr<Normal> normal = std::make_shared<Normal>(500);
  std::shared_ptr<Economy> economy = std::make_shared<Economy>();
  normal->setEconomy(economy);
  normal->decreasePopulation(200);  // Should transition to UnderPopulated
  EXPECT_EQ(normal->getPopulationCount(), 300);
  EXPECT_EQ(economy->getState()->getType(), "Under Populated");
}

TEST(NormalTest, increasePopulationWithinNormalRange) {
  std::shared_ptr<Normal> normal = std::make_shared<Normal>();
  normal->increasePopulation(500);
  EXPECT_EQ(normal->getPopulationCount(), 500);
  EXPECT_EQ(normal->getType(), "Normal Population");
}

TEST(NormalTest, getType) {
  std::shared_ptr<Normal> normal = std::make_shared<Normal>();
  EXPECT_EQ(normal->getType(), "Normal Population");
}

// Population testing done

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}