#include <SDL/SDL.h>
//#include <SDL/SDL_Image.h>
#include <string>
#include <iostream>
#include "model.hpp"
#include <SDL/SDL_rotozoom.h>
using namespace std;

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
//bounding box below since we will have a rotated sprite it would probably be best to do per pixel collisions
//   boundingbox.x=x;
 //  boundingbox.y=y;
 //  boundingbox.w=image->w;
 //  boundingbox.h=image->h;
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
void Model::draw(SDL_Surface *screen,int rotation)
{
    //here weshould call some SDL function for drawing to 
    // the screen. Use x and y. 
 
   SDL_Rect modelpos;
 //SDL_Surface * rotozoomSurface (SDL_Surface *src, double angle, double zoom, int smooth) 
   image= rotozoomSurface(image,(double)rotation,1,0); 
   modelpos.x=x;
   modelpos.y=y;
  // boundingbox.x=x;
  // boundingbox.y=y;   

   SDL_BlitSurface(image,NULL,screen,&modelpos);
  
}
