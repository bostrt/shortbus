#include <SDL/SDL.h>
#include <string>
#include <iostream>
#include "model.hpp"
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_image.h>
using namespace std;

// Constructor
Model::Model(double x1, double y1, string filename)
{
      image = IMG_Load(filename.c_str()); // We need to convert the string to a C-type string
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

SDL_Surface* Model::getSurface(){
    return image;
}

void Model::draw(SDL_Surface *screen,int rotation)
{
    //here weshould call some SDL function for drawing to 
    // the screen. Use x and y. 
    SDL_Surface* temprotate; 
    SDL_Rect modelpos;
    //SDL_Surface * rotozoomSurface (SDL_Surface *src, double angle, double zoom, int smooth) 
    temprotate = rotozoomSurface(image,rotation,1,1); 
    modelpos.x = x;
    modelpos.y = y;
    modelpos.w = temprotate->w;
    modelpos.h = temprotate->h; 
    SDL_BlitSurface(temprotate, NULL, screen, &modelpos);
}
