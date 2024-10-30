# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Executable name
TARGET = main

# Directories
SRC_DIR = .
OBJ_DIR = obj

# Source files
SRCS = $(SRC_DIR)/main.cpp \
       $(SRC_DIR)/game/Game.cpp \
       $(SRC_DIR)/game/Display.cpp \
       $(SRC_DIR)/map/MapComponent.cpp \
       $(SRC_DIR)/map/Map.cpp \
       $(SRC_DIR)/buildings/Building.cpp \
       $(SRC_DIR)/buildings/residential/ResidentialBuilding.cpp \
       $(SRC_DIR)/buildings/commercial/CommercialBuilding.cpp \
       $(SRC_DIR)/buildings/industrial/IndustrialBuilding.cpp \
       $(SRC_DIR)/buildings/utility/UtilityBuilding.cpp \
       $(SRC_DIR)/buildings/landmark/LandMark.cpp \
       $(SRC_DIR)/buildings/infrastructure/Infrastructure.cpp \
       $(SRC_DIR)/buildings/residential/Apartment.cpp \
       $(SRC_DIR)/buildings/residential/Estate.cpp \
       $(SRC_DIR)/buildings/residential/TownHouse.cpp \
       $(SRC_DIR)/buildings/residential/House.cpp \
       $(SRC_DIR)/buildings/commercial/Store.cpp \
       $(SRC_DIR)/buildings/commercial/Office.cpp \
       $(SRC_DIR)/buildings/commercial/Mall.cpp \
       $(SRC_DIR)/buildings/industrial/Factory.cpp \
       $(SRC_DIR)/buildings/industrial/Manufacturer.cpp \
       $(SRC_DIR)/buildings/industrial/Warehouse.cpp \
       $(SRC_DIR)/buildings/utility/PowerPlant.cpp \
       $(SRC_DIR)/buildings/utility/SewagePlant.cpp \
       $(SRC_DIR)/buildings/utility/WaterSupply.cpp \
       $(SRC_DIR)/buildings/utility/LandFill.cpp \
       $(SRC_DIR)/buildings/landmark/Monument.cpp \
       $(SRC_DIR)/buildings/landmark/CulturalCenter.cpp \
       $(SRC_DIR)/buildings/landmark/Park.cpp \
       $(SRC_DIR)/buildings/infrastructure/Road.cpp \
       $(SRC_DIR)/buildings/infrastructure/Railway.cpp \
       $(SRC_DIR)/buildings/transport/TransportBuilding.cpp \
       $(SRC_DIR)/buildings/transport/Airport.cpp \
       $(SRC_DIR)/buildings/transport/BusStation.cpp \
       $(SRC_DIR)/buildings/transport/TrainStation.cpp \
       $(SRC_DIR)/buildingFactories/BuildingFactory.cpp \
       $(SRC_DIR)/buildingFactories/CommercialBuildingFactory.cpp \
       $(SRC_DIR)/buildingFactories/IndustrialBuildingFactory.cpp \
       $(SRC_DIR)/buildingFactories/InfrastructureFactory.cpp \
       $(SRC_DIR)/buildingFactories/LandmarkBuildingFactory.cpp \
       $(SRC_DIR)/buildingFactories/ResidentialBuildingFactory.cpp \
       $(SRC_DIR)/buildingFactories/UtilityBuildingFactory.cpp \
       $(SRC_DIR)/buildingFactories/TransportBuildingFactory.cpp \
       $(SRC_DIR)/buildings/Upgrade.cpp \
       $(SRC_DIR)/buildings/upgrades/Solar.cpp \
       $(SRC_DIR)/buildings/upgrades/RainCatcher.cpp \
       $(SRC_DIR)/buildings/upgrades/Recycling.cpp \
       $(SRC_DIR)/buildings/upgrades/Garden.cpp \
       


# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Create directories if not exist
$(shell mkdir -p $(OBJ_DIR))

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Run target
run: $(TARGET)
	./$(TARGET)

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

.PHONY: clean run
