#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <memory>
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

#include "../Statistics.h"
//Includes for Transportation strategies
#include "../map/Transportation/TransportationStrategy.h"
#include "../map/Transportation/RoadStrategy.h"
#include "../map/Transportation/TrainStrategy.h"
#include "../map/Transportation/AirStrategy.h"
#include "../map/Transportation/PublicStrategy.h"


// Test construction of Display object
TEST(DisplayTest, ConstructorTest) {
    std::shared_ptr<Display> display = std::make_shared<Display>();
    ASSERT_NE(display, nullptr);
}

// Test getInput with valid input
TEST(DisplayTest, GetInputValidTest) {
    Display display;
    std::istringstream input("5\n"); // Valid input within range
    std::cin.rdbuf(input.rdbuf()); // Redirect standard input
    int result = display.getInput(1, 10); // Valid range from 1 to 10
    EXPECT_EQ(result, 5) << "Expected getInput to return 5 for valid input.";
}
// Test getInput with invalid non-integer input
TEST(DisplayTest, GetInputInvalidNonIntegerTest) {
    Display display;
    std::istringstream input("abc\n"); // Invalid input followed by a valid input
    std::cin.rdbuf(input.rdbuf());
    int result = display.getInput(1, 10);
    EXPECT_NE(result,"abc") << "Expected getInput to skip invalid input and accept 2.";
}
