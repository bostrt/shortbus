CXX=g++
CXXFLAGS=-g -lSDL -I/usr/include/X11 -lSDL_gfx -lSDL_image
PROJECT=shortbus

all: main.o wall.o aiopponent.o bus.o vehicle.o player.o model.o SDL_collide.o timer.o gamestate.o playstate.o
	$(CXX) $(CXXFLAGS) main.o wall.o aiopponent.o bus.o vehicle.o player.o model.o SDL_collide.o timer.o gamestate.o playstate.o -o $(PROJECT)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

wall.o: wall.cpp wall.hpp model.cpp 
	$(CXX) $(CXXFLAGS) -c wall.cpp -o wall.o

aiopponent.o: aiopponent.cpp model.cpp SDL_collide.c
	$(CXX) $(CXXFLAGS) -c aiopponent.cpp -o aiopponent.o

bus.o: bus.cpp bus.hpp vehicle.cpp
	$(CXX) $(CXXFLAGS) -c bus.cpp -o bus.o

vehicle.o: vehicle.cpp vehicle.hpp SDL_collide.c model.cpp aiopponent.cpp
	$(CXX) $(CXXFLAGS) -c vehicle.cpp -o vehicle.o

player.o: player.cpp player.hpp vehicle.cpp bus.cpp
	$(CXX) $(CXXFLAGS) -c player.cpp -o player.o

model.o: model.cpp model.hpp
	$(CXX) $(CXXFLAGS) -c model.cpp -o model.o

SDL_collide.o: SDL_collide.c SDL_collide.h
	$(CXX) $(CXXFLAGS) -c SDL_collide.c -o SDL_collide.o
	
timer.o: timer.cpp timer.hpp
	$(CXX) $(CXXFLAGS) -c timer.cpp -o timer.o
	
gamestate.o: gamestate.cpp gamestate.hpp timer.cpp
	$(CXX) $(CXXFLAGS) -c gamestate.cpp -o gamestate.o

playstate.o: playstate.cpp playstate.hpp gamestate.cpp
	$(CXX) $(CXXFLAGS) -c playstate.cpp -o playstate.o

clean:
	rm *.o $(PROJECT)
