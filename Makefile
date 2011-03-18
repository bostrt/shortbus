CXX=g++
C=gcc
CXXFLAGS=-g -lSDL -I/usr/include/X11 -lSDL_gfx -lSDL_image
PROJECT=shortbus

all: main.o wall.o aiopponents.o bus.o vehicle.o player.o model.o SDL_collide.o
	$(CXX) $(CXXFLAGS) main.o wall.o aiopponents.o bus.o vehicle.o player.o model.o SDL_collide.o -o $(PROJECT)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

wall.o: wall.cpp 
	$(CXX) $(CXXFLAGS) -c wall.cpp -o wall.o

aiopponents.o: aiopponents.cpp
	$(CXX) $(CXXFLAGS) -c aiopponents.cpp -o aiopponents.o

bus.o: bus.cpp bus.hpp
	$(CXX) $(CXXFLAGS) -c bus.cpp -o bus.o

vehicle.o: vehicle.cpp vehicle.hpp
	$(CXX) $(CXXFLAGS) -c vehicle.cpp -o vehicle.o

player.o: player.cpp player.hpp
	$(CXX) $(CXXFLAGS) -c player.cpp -o player.o

model.o: model.cpp model.hpp
	$(CXX) $(CXXFLAGS) -c model.cpp -o model.o
SDL_collide.o: SDL_collide.c SDL_collide.h
	$(C)   $(CXXFLAGS) -c SDL_collide.c -o SDL_collide.o
clean:
	rm *.o $(PROJECT)
