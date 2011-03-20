#include <SDL/SDL.h>
#include <string>
#include <iostream>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_image.h>

#include "model.hpp"

using namespace std;

// Constructor
Model::Model(int x1, int y1, string filename)
{
	image = IMG_Load(filename.c_str()); // We need to convert the string to a C-type string
	x = x1;
	y = y1;
	SDL_GetClipRect(image, &clip);
}

int Model::getX(){
	return x;
}

int Model::getY(){
	return y;
}

void Model::setX(int x1){
	x = x1;
}

void Model::setY(int y1){
	y = y1;
}

SDL_Surface* Model::getSurface(){
	return image;
}
void Model::setSurface(SDL_Surface* surface){image=surface;}

void Model::draw(SDL_Surface *screen,int rotation)
{
	//here weshould call some SDL function for drawing to
	// the screen. Use x and y.
	SDL_Surface* temprotate;
	temprotate = rotozoomSurface(image,rotation,1,1);
	clip.x = x;
	clip.y = y;
	clip.w = temprotate->w;
	clip.h = temprotate->h;
	SDL_Rect dest;
	SDL_GetClipRect(image, &dest);
	dest.w += 100;
	SDL_BlitSurface(temprotate, &dest , screen, &clip);
}

void Model::draw(SDL_Surface *screen)
{
	SDL_Rect modelposlol;
	modelposlol.x = x;
	modelposlol.y = y;
	modelposlol.w = image->w;
	modelposlol.w = image->h;
	SDL_BlitSurface(image, NULL, screen, &modelposlol);
}
