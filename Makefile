# Compiler symbols

CXX := g++
CXXFLAGS := -g -O2

INCLUDES := .

OBJECTS := main.o

SOURCE := main.cpp game_object.cpp

MY_PROGRAM := app

all: $(MY_PROGRAM)

# Link command:

$(MY_PROGRAM): $(SOURCE)
	$(CXX) -I$(INCLUDES) $(CXXFLAGS) $(SOURCE) -o $(MY_PROGRAM)

#%.o: %.cpp
#	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $(input) -o $(output)

clean:
	rm -rf $(MY_PROGRAM)
