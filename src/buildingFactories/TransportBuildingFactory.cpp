#include "TransportBuildingFactory.h"

TransportBuildingFactory::TransportBuildingFactory(int id)
: BuildingFactory(id)
{
}

void TransportBuildingFactory::createBuilding(string variant) {
    if (buildingId >= 100) // 99 max buildings
    {
        cout << "You have reached the maximum number of Transport buildings" << endl;
        return;
    }

    int idForBuilding = buildingId + 100 * id;
    buildingId++;
    if (variant == "Airport")
    {
        buildings.push_back(make_shared<Airport>(idForBuilding));
    }
    else if (variant == "BusStation")
    {
        buildings.push_back(make_shared<BusStation>(idForBuilding));
    }
    else if (variant == "TrainStation")
    {
        buildings.push_back(make_shared<TrainStation>(idForBuilding));
    }
    else
    {
        cout << "Invalid building type" << endl;
        buildingId--;
    }
}
//
std::shared_ptr<Building> TransportBuildingFactory::createBuilding2(const string& variant) {
    if (buildingId >= 100) // 99 max buildings
    {
        cout << "You have reached the maximum number of Transport buildings" << endl;
        return nullptr;
    }

    int idForBuilding = buildingId + 100 * id;
    buildingId++;
    std::shared_ptr<Building> newBuilding;
    if (variant == "Airport")
    {
        newBuilding = std::make_shared<Airport>(idForBuilding);
        buildings.push_back(make_shared<Airport>(idForBuilding));
    }
    else if (variant == "BusStation")
    {
        newBuilding = std::make_shared<BusStation>(idForBuilding);
        buildings.push_back(make_shared<BusStation>(idForBuilding));
    }
    else if (variant == "TrainStation")
    {
        newBuilding = std::make_shared<TrainStation>(idForBuilding);
        buildings.push_back(make_shared<TrainStation>(idForBuilding));
    }
    else
    {
        cout << "Invalid building type" << endl;
        buildingId--;
    }
    newBuilding->print();
    return newBuilding;
}

//

TransportBuildingFactory::~TransportBuildingFactory()
{
}

void TransportBuildingFactory::print() {
    cout << "Printing Transport Buildings" << endl;
    for (auto building : buildings)
    {
        building->print();
    }
}