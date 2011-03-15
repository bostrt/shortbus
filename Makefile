CXX=g++
CXXFLAGS=-g -lSDL
PROJECT=sedex

all: main.o walls.o aiopponents.o
	$(CXX) $(CXXFLAGS) main.o walls.o -o sedex

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

walls.o: walls.cpp 
	$(CXX) $(CXXFLAGS) -c walls.cpp -o walls.o

aiopponents.o: aiopponents.cpp
	$(CXX) $(CXXFLAGS) -c aiopponents.cpp -o aiopponents.o

clean:
	rm *.o $(PROJECT)