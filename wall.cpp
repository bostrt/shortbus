#include <SDL/SDL.h>
#include <string>
#include "wall.hpp"

using namespace std;
extern SDL_Surface *screen;

Wall::Wall(int xPos,int yPos,string filename):Model(xPos,yPos,filename){
     
}void Wall::update(Model* world[]){}
//void Wall::draw(int xPos,int yPos,int width,int height)
//}
