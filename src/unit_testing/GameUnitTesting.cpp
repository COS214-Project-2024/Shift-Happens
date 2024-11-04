#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <string>
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

//Constructor Test
TEST(GameTest, ConstructorTest) {
    std::shared_ptr<Game> game = std::make_shared<Game>();
    ASSERT_NE(game, nullptr);
}

//MainMenu
TEST(GameTest, MenuValidTest) {
    std::shared_ptr<Game> game = std::make_shared<Game>();
    std::istringstream input("1/n");//simulate choosing new game
    std::cin.rdbuf(input.rdbuf() ) ;

    testing::internal::CaptureStdout();
    game->MainMenu();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Please select an option.") );
    //expected this message when display gamemenu plays


}
TEST(GameTest, MenuInvalidTest)
{
    std::shared_ptr<Game> game = std::make_shared<Game>();
    std::istringstream input("5/n");//simulate choosing new game
    std::cin.rdbuf(input.rdbuf() ) ;

    testing::internal::CaptureStdout();
    game->MainMenu();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("error: invalid input main menu") );
    //expected this message when display gamemenu plays


}






int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}