#include <SDL/SDL.h>
#include <string>
#include <vector>
#include "wall.hpp"

using namespace std;
extern SDL_Surface *screen;

Wall::Wall(int xPos,int yPos,string filename):Model(xPos,yPos,filename){
     
}

void Wall::update(std::vector<Model *> world){
}
