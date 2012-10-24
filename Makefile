# Compiler symbols

CXX := g++
CXXFLAGS := -g -O2

INCLUDES := .

OBJECTS := Main.o GameObject.o LiquidSystems.o EngineSystems.o

SOURCE := Main.cpp GameObject.cpp LiquidSystems.cpp

MY_PROGRAM := Application

all: $(MY_PROGRAM)

# Link command:

$(MY_PROGRAM): $(OBJECTS)
	$(CXX) -I$(INCLUDES) $(CXXFLAGS) $(OBJECTS) -o $(MY_PROGRAM)

Main.o: Main.cpp
	$(CXX) -c -I$(INCLUDES) $(CXXFLAGS) Main.cpp -o Main.o

LiquidSystems.o: LiquidSystems.cpp
	$(CXX) -c -I$(INCLUDES) $(CXXFLAGS) LiquidSystems.cpp -o LiquidSystems.o

GameObject.o: GameObject.cpp
	$(CXX) -c -I$(INCLUDES) $(CXXFLAGS) GameObject.cpp -o GameObject.o

EngineSystems.o: EngineSystems.cpp
	$(CXX) -c -I$(INCLUDES) $(CXXFLAGS) EngineSystems.cpp -o EngineSystems.o

ElectricalSystems.o: ElectricalSystems.cpp
	$(CXX) -c -I$(INCLUDES) $(CXXFLAGS) ElectricalSystems.cpp -o ElectricalSystems.o

#%.o: %.cpp
#	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(input) -o $(output)

clean:
	rm -rf $(MY_PROGRAM) $(OBJECTS)
