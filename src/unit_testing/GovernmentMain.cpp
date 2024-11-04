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
#include "../Government/Government.h"
#include "../Government/StandardTax.h"
#include "../Government/LowTax.h"
#include "../Government/HighTax.h"

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

TEST(NormalPopulationTest, increasePopulationWithTransition) {
  std::shared_ptr<Normal> normal = std::make_shared<Normal>();
  std::shared_ptr<Economy> economy = std::make_shared<Economy>();
  normal->setEconomy(economy);
  normal->increasePopulation(2500);  // Should transition to OverPopulated
  EXPECT_EQ(normal->getPopulationCount(), 2500);
  EXPECT_EQ(economy->getState()->getType(), "Over Populated");
}

TEST(NormalPopulationTest, decreasePopulationWithTransition) {
  std::shared_ptr<Normal> normal = std::make_shared<Normal>(500);
  std::shared_ptr<Economy> economy = std::make_shared<Economy>();
  normal->setEconomy(economy);
  normal->decreasePopulation(200);  // Should transition to UnderPopulated
  EXPECT_EQ(normal->getPopulationCount(), 300);
  EXPECT_EQ(economy->getState()->getType(), "Under Populated");
}

TEST(NormalPopulationTest, increasePopulationWithinNormalRange) {
  std::shared_ptr<Normal> normal = std::make_shared<Normal>();
  normal->increasePopulation(500);
  EXPECT_EQ(normal->getPopulationCount(), 500);
  EXPECT_EQ(normal->getType(), "Normal Population");
}

TEST(NormalPopulationTest, getType) {
  std::shared_ptr<Normal> normal = std::make_shared<Normal>();
  EXPECT_EQ(normal->getType(), "Normal Population");
}

// Population testing done

//Tax testing 
TEST(StandardTaxTesting, increaseTaxWithTransition){
  std::shared_ptr<Government> government = make_shared<Government>();
  std::shared_ptr<StandardTax> standard = make_shared<StandardTax>();

  EXPECT_EQ(government->getTax()->getType(), "Standard Tax");
  EXPECT_EQ(government->getBusinessTax()->getType(), "Standard Tax");

  
  government->setPersonalTaxHigher(20);
  government->setBusinessTaxHigher(25);

  EXPECT_EQ(standard->getRate(), 40);
  EXPECT_EQ(standard->getBusinessRate(), 32);

  EXPECT_EQ(government->getTax()->getType(), "High Tax");
  EXPECT_EQ(government->getBusinessTax()->getType(), "High Tax");

}

TEST(StandardTaxTesting, increaseTaxWithoutTransition){
  std::shared_ptr<Government> government = make_shared<Government>();
  std::shared_ptr<StandardTax> standard = make_shared<StandardTax>();

  EXPECT_EQ(government->getTax()->getType(), "Standard Tax");
  EXPECT_EQ(government->getBusinessTax()->getType(), "Standard Tax");

  
  government->setPersonalTaxHigher(10);
  government->setBusinessTaxHigher(10);

  EXPECT_EQ(standard->getRate(), 30);
  EXPECT_EQ(standard->getBusinessRate(), 17);

  EXPECT_EQ(government->getTax()->getType(), "Standard Tax");
  EXPECT_EQ(government->getBusinessTax()->getType(), "Standard Tax");

}

TEST(StandardTaxTesting, decreaseTaxWithTransition){
  std::shared_ptr<Government> government = make_shared<Government>();
  std::shared_ptr<StandardTax> standard = make_shared<StandardTax>();

  EXPECT_EQ(government->getTax()->getType(), "Standard Tax");
  EXPECT_EQ(government->getBusinessTax()->getType(), "Standard Tax");

  
  government->setPersonalTaxLower(20);
  government->setBusinessTaxLower(25);

  EXPECT_EQ(standard->getRate(), 0);
  EXPECT_EQ(standard->getBusinessRate(), 0);

  EXPECT_EQ(government->getTax()->getType(), "Low Tax");
  EXPECT_EQ(government->getBusinessTax()->getType(), "Low Tax");

}

TEST(StandardTaxTesting, decreaseTaxWithoutTransition){
  std::shared_ptr<Government> government = make_shared<Government>();
  std::shared_ptr<StandardTax> standard = make_shared<StandardTax>();

  EXPECT_EQ(government->getTax()->getType(), "Standard Tax");
  EXPECT_EQ(government->getBusinessTax()->getType(), "Standard Tax");

  
  government->setPersonalTaxLower(0);
  government->setBusinessTaxHigher(0);

  EXPECT_EQ(standard->getRate(), 20);
  EXPECT_EQ(standard->getBusinessRate(), 7);

  EXPECT_EQ(government->getTax()->getType(), "Standard Tax");
  EXPECT_EQ(government->getBusinessTax()->getType(), "Standard Tax");

}

TEST(StandardTaxTesting, decreaseTaxWithoutTransition){
  std::shared_ptr<StandardTax> standard = make_shared<StandardTax>();
  EXPECT_EQ(standard->getType(), "Standard Tax");

}

// LowTax Testing
TEST(LowTaxTesting, increaseTaxWithTransition) {
    std::shared_ptr<Government> government = make_shared<Government>();
    std::shared_ptr<LowTax> lowTax = make_shared<LowTax>();

    EXPECT_EQ(government->getTax()->getType(), "Low Tax");
    EXPECT_EQ(government->getBusinessTax()->getType(), "Low Tax");

    government->setPersonalTaxHigher(25);
    government->setBusinessTaxHigher(10);

    EXPECT_EQ(lowTax->getRate(), 22); 
    EXPECT_EQ(lowTax->getBusinessRate(), 7.5);

    EXPECT_EQ(government->getTax()->getType(), "Standard Tax");
    EXPECT_EQ(government->getBusinessTax()->getType(), "Standard Tax");
}

TEST(LowTaxTesting, increaseTaxWithoutTransition) {
    std::shared_ptr<Government> government = make_shared<Government>();
    std::shared_ptr<LowTax> lowTax = make_shared<LowTax>();

    EXPECT_EQ(government->getTax()->getType(), "Low Tax");
    EXPECT_EQ(government->getBusinessTax()->getType(), "Low Tax");

    government->setPersonalTaxHigher(5);
    government->setBusinessTaxHigher(2);

    EXPECT_EQ(lowTax->getRate(), 15); 
    EXPECT_EQ(lowTax->getBusinessRate(), 4.5); 

    EXPECT_EQ(government->getTax()->getType(), "Low Tax");
    EXPECT_EQ(government->getBusinessTax()->getType(), "Low Tax");
}

TEST(LowTaxTesting, decreaseTaxWithTransition) {
    std::shared_ptr<Government> government = make_shared<Government>();
    std::shared_ptr<LowTax> lowTax = make_shared<LowTax>();

    EXPECT_EQ(government->getTax()->getType(), "Low Tax");
    EXPECT_EQ(government->getBusinessTax()->getType(), "Low Tax");

    government->setPersonalTaxLower(15);
    government->setBusinessTaxLower(8);

    EXPECT_EQ(lowTax->getRate(), 0);
    EXPECT_EQ(lowTax->getBusinessRate(), 0); 

    EXPECT_EQ(government->getTax()->getType(), "Low Tax"); 
    EXPECT_EQ(government->getBusinessTax()->getType(), "Low Tax");
}

TEST(LowTaxTesting, decreaseTaxWithoutTransition) {
    std::shared_ptr<Government> government = make_shared<Government>();
    std::shared_ptr<LowTax> lowTax = make_shared<LowTax>();

    EXPECT_EQ(government->getTax()->getType(), "Low Tax");
    EXPECT_EQ(government->getBusinessTax()->getType(), "Low Tax");

    government->setPersonalTaxLower(5);
    government->setBusinessTaxLower(2);

    EXPECT_EQ(lowTax->getRate(), 5);
    EXPECT_EQ(lowTax->getBusinessRate(), 1.5);

    EXPECT_EQ(government->getTax()->getType(), "Low Tax");
    EXPECT_EQ(government->getBusinessTax()->getType(), "Low Tax");
}

TEST(LowTaxTesting, initialTypeCheck) {
    std::shared_ptr<LowTax> lowTax = make_shared<LowTax>();
    EXPECT_EQ(lowTax->getType(), "Low Tax");
}


TEST(HighTaxTesting, decreaseTaxWithTransition) {
    std::shared_ptr<Government> government = std::make_shared<Government>();
    std::shared_ptr<HighTax> highTax = std::make_shared<HighTax>();

    EXPECT_EQ(government->getTax()->getType(), "High Tax");
    EXPECT_EQ(government->getBusinessTax()->getType(), "High Tax");

    government->setPersonalTaxLower(10);
    government->setBusinessTaxLower(5);

    EXPECT_EQ(highTax->getRate(), 25);
    EXPECT_EQ(highTax->getBusinessRate(), 22);

    EXPECT_EQ(government->getTax()->getType(), "Standard Tax");
    EXPECT_EQ(government->getBusinessTax()->getType(), "Standard Tax");
}

TEST(HighTaxTesting, decreaseTaxWithoutTransition) {
    std::shared_ptr<Government> government = std::make_shared<Government>();
    std::shared_ptr<HighTax> highTax = std::make_shared<HighTax>();

    EXPECT_EQ(government->getTax()->getType(), "High Tax");
    EXPECT_EQ(government->getBusinessTax()->getType(), "High Tax");

    government->setPersonalTaxLower(5);
    government->setBusinessTaxLower(2);

    EXPECT_EQ(highTax->getRate(), 30);
    EXPECT_EQ(highTax->getBusinessRate(), 25);

    EXPECT_EQ(government->getTax()->getType(), "High Tax");
    EXPECT_EQ(government->getBusinessTax()->getType(), "High Tax");
}

TEST(HighTaxTesting, increaseTaxWithoutTransition) {
  std::shared_ptr<HighTax> highTax = std::make_shared<HighTax>();
  EXPECT_EQ(highTax->getType(), "High Tax");
}


// Public services state testing
TEST(OutdatedServiceTesting, getType){
  std::shared_ptr<Outdated> outdated = make_shared<Outdated>();
  EXPECT_EQ(outdated->getType(), "Outdated Services");
}

TEST(OutdatedServiceTesting, increaseWithTransition){
  std::shared_ptr<Outdated> outdated = make_shared<Outdated>();
  std::shared_ptr<Public_Services> publicService = make_shared<Police>();
  outdated->setPublicService(publicService);

  EXPECT_EQ(outdated->getType(), "Outdated Services");

  outdated->increaseBudget(120);

  EXPECT_EQ(outdated->getRunningBudget(), 120);
  EXPECT_EQ(publicService->getState()->getType(), "Standard Services");
  
}

TEST(OutdatedServiceTesting, increaseWithoutTransition){
  std::shared_ptr<Outdated> outdated = make_shared<Outdated>();
  std::shared_ptr<Public_Services> publicService = make_shared<Police>();
  outdated->setPublicService(publicService);

  EXPECT_EQ(outdated->getType(), "Outdated Services");

  outdated->increaseBudget(80);

  EXPECT_EQ(outdated->getRunningBudget(), 80);
  EXPECT_EQ(publicService->getState()->getType(), "Outdated Services");
}

TEST(OutdatedServiceTesting, decreaseWithOutTransition){
  std::shared_ptr<Outdated> outdated = make_shared<Outdated>();
  std::shared_ptr<Public_Services> publicService = make_shared<Police>();
  outdated->setPublicService(publicService);

  EXPECT_EQ(outdated->getType(), "Outdated Services");

  outdated->decreaseBudget(80);

  EXPECT_EQ(outdated->getRunningBudget(), 0);
  EXPECT_EQ(publicService->getState()->getType(), "Outdated Services");
}

TEST(StandardServiceTesting, getType) {
    std::shared_ptr<Standard> standard = std::make_shared<Standard>();
    EXPECT_EQ(standard->getType(), "Standard Services");
}

TEST(StandardServiceTesting, increaseWithTransition) {
    std::shared_ptr<Standard> standard = std::make_shared<Standard>();
    std::shared_ptr<Public_Services> publicService = std::make_shared<Police>();
    standard->setPublicService(publicService);

    EXPECT_EQ(standard->getType(), "Standard Services");

    standard->increaseBudget(900);

    EXPECT_EQ(standard->getRunningBudget(), 1000);
    EXPECT_EQ(publicService->getState()->getType(), "Modern Services");
}

TEST(StandardServiceTesting, increaseWithoutTransition) {
    std::shared_ptr<Standard> standard = std::make_shared<Standard>();
    std::shared_ptr<Public_Services> publicService = std::make_shared<Police>();
    standard->setPublicService(publicService);

    EXPECT_EQ(standard->getType(), "Standard Services");

    standard->increaseBudget(400);

    EXPECT_EQ(standard->getRunningBudget(), 500);
    EXPECT_EQ(publicService->getState()->getType(), "Standard Services");
}

TEST(StandardServiceTesting, decreaseWithoutTransition) {
    std::shared_ptr<Standard> standard = std::make_shared<Standard>();
    std::shared_ptr<Public_Services> publicService = std::make_shared<Police>();
    standard->setPublicService(publicService);

    EXPECT_EQ(standard->getType(), "Standard Services");

    standard->decreaseBudget(50);

    EXPECT_EQ(standard->getRunningBudget(), 50);
    EXPECT_EQ(publicService->getState()->getType(), "Standard Services");
}

TEST(StandardServiceTesting, decreaseWithTransition) {
  std::shared_ptr<Standard> standard = std::make_shared<Standard>();
  std::shared_ptr<Public_Services> publicService = std::make_shared<Police>();
  standard->setPublicService(publicService);

  EXPECT_EQ(standard->getType(), "Standard Services");

  standard->decreaseBudget(200);

  EXPECT_EQ(standard->getRunningBudget(), 0);
  EXPECT_EQ(publicService->getState()->getType(), "Outdated Services");
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}