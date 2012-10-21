# Compiler symbols

CXX := g++
CXXFLAGS := -g -O2

INCLUDES := .

OBJECTS := main.o game_object.o liquid_systems.o

SOURCE := main.cpp game_object.cpp liquid_systems.cpp

MY_PROGRAM := app

all: $(MY_PROGRAM)

# Link command:

$(MY_PROGRAM): $(OBJECTS)
	$(CXX) -I$(INCLUDES) $(CXXFLAGS) $(OBJECTS) -o $(MY_PROGRAM)

main.o: main.cpp
	$(CXX) -c -I$(INCLUDES) $(CXXFLAGS) main.cpp -o main.o

liquid_systems.o: liquid_systems.cpp
	$(CXX) -c -I$(INCLUDES) $(CXXFLAGS) liquid_systems.cpp -o liquid_systems.o

game_object.o: game_object.cpp
	$(CXX) -c -I$(INCLUDES) $(CXXFLAGS) game_object.cpp -o game_object.o

#%.o: %.cpp
#	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(input) -o $(output)

clean:
	rm -rf $(MY_PROGRAM) $(OBJECTS)
