CXX=g++
CXXFLAGS=-g -lSDL
PROJECT=sedex

all: main.o walls.o aiopponents.o bus.o vehicle.o player.o
	$(CXX) $(CXXFLAGS) main.o walls.o -o sedex

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

walls.o: walls.cpp 
	$(CXX) $(CXXFLAGS) -c walls.cpp -o walls.o

aiopponents.o: aiopponents.cpp
	$(CXX) $(CXXFLAGS) -c aiopponents.cpp -o aiopponents.o

bus.o: bus.cpp bus.hpp
	$(CXX) $(CXXFLAGS) -c bus.cpp -o bus.o

vehicle.o: vehicle.cpp vehicle.hpp
	$(CXX) $(CXXFLAGS) -c vehicle.cpp -o vehicle.o

player.o: player.cpp
	$(CXX) $(CXXFLAGS) -c player.cpp -o player.o

clean:
	rm *.o $(PROJECT)