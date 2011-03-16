#include <SDL/SDL.h>
#include <string>
#include "model.hpp"
using namespace std;
extern SDL_Surface* screen;

// Constructor
Model::Model(double x1, double y1, string filename)
{
    char *cfilename;
    cfilename = new char[filename.length() + 1];
    strcpy(cfilename, filename.c_str());
    image=SDL_LoadBMP(cfilename);
    
    // TODO: Load and set SDL_Surface
    x = x1;
    y = y1;
   boundingbox.x=x;
   boundingbox.y=y;
   boundingbox.w=image->w;
   boundingbox.h=image->h;
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
void Model::draw()
{
    //here weshould call some SDL function for drawing to 
    // the screen. Use x and y. 
 
   SDL_Rect modelpos;
   
   modelpos.x=x;
   modelpos.y=y;
   boundingbox.x=x;
   boundingbox.y=y;   
   SDL_BlitSurface(image,NULL,screen,&modelpos);
}
