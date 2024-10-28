# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g  # The -g flag is for generating debugging information

# Target executable
TARGET = main.exe

# Source files
SRCS = main.cpp game/Game.cpp game/Display.cpp map/MapComponent.cpp map/Map.cpp \
		buildings/Building.cpp \
		buildings/residential/Apartment.cpp buildings/residential/Estate.cpp buildings/residential/TownHouse.cpp buildings/residential/House.cpp \
		buildings/commercial/Store.cpp buildings/commercial/Office.cpp buildings/commercial/Mall.cpp \
		buildings/industrial/Factory.cpp buildings/industrial/Manufacturer.cpp buildings/industrial/Warehouse.cpp \
		
       
# Object files
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Rule to compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Run with Valgrind for memory leak detection
valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

# Run with gdb for debugging
gdb: $(TARGET)
	gdb ./$(TARGET)
