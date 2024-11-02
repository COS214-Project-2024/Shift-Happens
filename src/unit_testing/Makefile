# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Directories
SRC_DIR = .
OBJ_DIR = obj

# Google Test Libraries
GTEST_LIBS = -lgtest -lgtest_main -pthread

# Main source files
POLICY_MAIN = $(SRC_DIR)/PolicyMain.cpp
GOVERNMENT_MAIN = $(SRC_DIR)/GovernmentMain.cpp
CITIZEN_MAIN = $(SRC_DIR)/CitizenUnitTesting.cpp
MAIN_CPP = $(SRC_DIR)/main.cpp

# Common source files
COMMON_SRCS = $(SRC_DIR)/../game/Game.cpp \
       $(SRC_DIR)/../game/Display.cpp \
       $(SRC_DIR)/../map/MapComponent.cpp \
       $(SRC_DIR)/../map/Map.cpp \
       $(SRC_DIR)/../buildings/Building.cpp \
       $(SRC_DIR)/../buildings/residential/ResidentialBuilding.cpp \
       $(SRC_DIR)/../buildings/commercial/CommercialBuilding.cpp \
       $(SRC_DIR)/../buildings/industrial/IndustrialBuilding.cpp \
       $(SRC_DIR)/../buildings/utility/UtilityBuilding.cpp \
       $(SRC_DIR)/../buildings/landmark/LandMark.cpp \
       $(SRC_DIR)/../buildings/infrastructure/Infrastructure.cpp \
       $(SRC_DIR)/../buildings/residential/Apartment.cpp \
       $(SRC_DIR)/../buildings/residential/Estate.cpp \
       $(SRC_DIR)/../buildings/residential/TownHouse.cpp \
       $(SRC_DIR)/../buildings/residential/House.cpp \
       $(SRC_DIR)/../buildings/commercial/Store.cpp \
       $(SRC_DIR)/../buildings/commercial/Office.cpp \
       $(SRC_DIR)/../buildings/commercial/Mall.cpp \
       $(SRC_DIR)/../buildings/industrial/Factory.cpp \
       $(SRC_DIR)/../buildings/industrial/Manufacturer.cpp \
       $(SRC_DIR)/../buildings/industrial/Warehouse.cpp \
       $(SRC_DIR)/../buildings/utility/PowerPlant.cpp \
       $(SRC_DIR)/../buildings/utility/SewagePlant.cpp \
       $(SRC_DIR)/../buildings/utility/WaterSupply.cpp \
       $(SRC_DIR)/../buildings/utility/LandFill.cpp \
       $(SRC_DIR)/../buildings/landmark/Monument.cpp \
       $(SRC_DIR)/../buildings/landmark/CulturalCenter.cpp \
       $(SRC_DIR)/../buildings/landmark/Park.cpp \
       $(SRC_DIR)/../buildings/infrastructure/Road.cpp \
       $(SRC_DIR)/../buildings/infrastructure/Railway.cpp \
       $(SRC_DIR)/../buildings/transport/TransportBuilding.cpp \
       $(SRC_DIR)/../buildings/transport/Airport.cpp \
       $(SRC_DIR)/../buildings/transport/BusStation.cpp \
       $(SRC_DIR)/../buildings/transport/TrainStation.cpp \
       $(SRC_DIR)/../buildingFactories/BuildingFactory.cpp \
       $(SRC_DIR)/../buildingFactories/CommercialBuildingFactory.cpp \
       $(SRC_DIR)/../buildingFactories/IndustrialBuildingFactory.cpp \
       $(SRC_DIR)/../buildingFactories/InfrastructureFactory.cpp \
       $(SRC_DIR)/../buildingFactories/LandmarkBuildingFactory.cpp \
       $(SRC_DIR)/../buildingFactories/ResidentialBuildingFactory.cpp \
       $(SRC_DIR)/../buildingFactories/UtilityBuildingFactory.cpp \
       $(SRC_DIR)/../buildingFactories/TransportBuildingFactory.cpp \
       $(SRC_DIR)/../Government/Standard.cpp \
       $(SRC_DIR)/../Government/Outdated.cpp \
       $(SRC_DIR)/../Government/Modern.cpp \
       $(SRC_DIR)/../Government/PublicServices.cpp \
       $(SRC_DIR)/../Government/CitySubject.cpp \
       $(SRC_DIR)/../Government/Education.cpp \
       $(SRC_DIR)/../Government/HealthCare.cpp \
       $(SRC_DIR)/../Government/Police.cpp \
       $(SRC_DIR)/../Government/BoostHealthCarePolicy.cpp \
       $(SRC_DIR)/../Government/BoostPolicePolicy.cpp \
       $(SRC_DIR)/../Government/BoostEducationPolicy.cpp \
       $(SRC_DIR)/../Government/Government.cpp \
       $(SRC_DIR)/../Government/Policy.cpp \
       $(SRC_DIR)/../Government/Tax.cpp \
       $(SRC_DIR)/../Government/StandardTax.cpp \
       $(SRC_DIR)/../Government/HighTax.cpp \
       $(SRC_DIR)/../Government/LowTax.cpp \
       $(SRC_DIR)/../Government/Economy.cpp \
       $(SRC_DIR)/../citizens/Boy.cpp \
       $(SRC_DIR)/../citizens/BoyBuilder.cpp \
       $(SRC_DIR)/../citizens/Citizen.cpp \
       $(SRC_DIR)/../citizens/Director.cpp \
       $(SRC_DIR)/../citizens/Girl.cpp \
       $(SRC_DIR)/../citizens/GirlBuilder.cpp \
       $(SRC_DIR)/../citizens/Man.cpp \
       $(SRC_DIR)/../citizens/ManBuilder.cpp \
       $(SRC_DIR)/../citizens/Woman.cpp \
       $(SRC_DIR)/../citizens/WomanBuilder.cpp 
       


# Object files for common sources
COMMON_OBJS = $(COMMON_SRCS:$(SRC_DIR)/../%.cpp=$(OBJ_DIR)/%.o)

# Object files for each main file
POLICY_MAIN_OBJ = $(OBJ_DIR)/PolicyMain.o
GOVERNMENT_MAIN_OBJ = $(OBJ_DIR)/GovernmentMain.o
CITIZEN_MAIN_OBJ = $(OBJ_DIR)/CitizenUnitTesting.o
MAIN_OBJ = $(OBJ_DIR)/main.o

# Executable names
POLICY_EXEC = policy_exec
GOVERNMENT_EXEC = government_exec
CITIZEN_EXEC = citizen_exec
MAIN_EXEC = main_exec

# Build target for PolicyMain
$(POLICY_EXEC): $(POLICY_MAIN_OBJ) $(COMMON_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIBS)

# Build target for GovernmentMain
$(GOVERNMENT_EXEC): $(GOVERNMENT_MAIN_OBJ) $(COMMON_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIBS)

# Build target for CitizenMain
$(CITIZEN_EXEC): $(CITIZEN_MAIN_OBJ) $(COMMON_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_LIBS)

# Build target for main.cpp
$(MAIN_EXEC): $(MAIN_OBJ) $(COMMON_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to build object files for main files
$(OBJ_DIR)/PolicyMain.o: $(POLICY_MAIN)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)/GovernmentMain.o: $(GOVERNMENT_MAIN)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)/CitizenUnitTesting.o: $(CITIZEN_MAIN)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)/main.o: $(MAIN_CPP)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Rule to build object files for common sources
$(OBJ_DIR)/%.o: $(SRC_DIR)/../%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Run targets
run_policy: $(POLICY_EXEC)
	./$(POLICY_EXEC)

run_government: $(GOVERNMENT_EXEC)
	./$(GOVERNMENT_EXEC)

run_citizen: $(CITIZEN_EXEC)
	./$(CITIZEN_EXEC)

run_main: $(MAIN_EXEC)
	./$(MAIN_EXEC)

# Clean up
clean:
	rm -rf $(OBJ_DIR) $(POLICY_EXEC) $(GOVERNMENT_EXEC) $(CITIZEN_EXEC) $(MAIN_EXEC)

.PHONY: clean run_policy run_government run_citizen run_main
