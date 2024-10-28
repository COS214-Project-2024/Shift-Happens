#include <iostream>
#include "game/Game.h"

#include "buildingFactories/BuildingFactory.h"
#include "buildingFactories/CommercialBuildingFactory.h"
#include "buildingFactories/IndustrialBuildingFactory.h"
#include "buildingFactories/InfrastructureFactory.h"
#include "buildingFactories/ResidentialBuildingFactory.h"

#include "buildings/Building.h"
#include "buildings/commercial/CommercialBuilding.h"
#include "buildings/industrial/IndustrialBuilding.h"
#include "buildings/infrastructure/Infrastructure.h"
#include "buildings/residential/ResidentialBuilding.h"

#include "game/Game.h"

using namespace std;

void demo() {
    Game game;
    game.run();
}

void testBuildingFactory() {
    BuildingFactory *factory = new ResidentialBuildingFactory(1);
    


}
int main() {
    //demo();
    testBuildingFactory();
    return 0;
}