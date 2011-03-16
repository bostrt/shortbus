#include <SDL/SDL.h>
#include <string>
#include "model.hpp"

extern SDL_Surface* screen;

// Constructor
Model::Model(double x1, double y1, std::string filename)
{
    // TODO: Load and set SDL_Surface
    x = x1;
    y = y1;
}

double Model::getX(){
    return x;
}

double Model::getY(){
    return y;
}

void Model::setX(double x1){
    x = x1;
}

void Model::setY(double y1){
    y = y1;
}
void Model::draw(SDL_Surface* modeldraw)
{
    //here weshould call some SDL function for drawing to 
    // the screen. Use x and y. 
 
  SDL_Rect modelpos;

   modelpos.x=x;
   modelpos.y=y;
   SDL_BlitSurface(modeldraw,NULL,screen,&modelpos);
}
