#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "tile.hpp"
#include <string>
Tile:Tile(SDL_Rect location,string filename){
	SDL_Surface * tempimage = IMG_LOAD(filename.c_string());
	SDL_BlitSurface(tempimage,&location,tilesurface,NULL);
}
SDL_Surface* Tile:returnSurface(){
	return tilesurface;
}
