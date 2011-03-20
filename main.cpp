#ifdef __cplusplus
#include <cstdlib>
#else
#include <stdlib.h>
#endif
#include <SDL/SDL.h>
#include <iostream>

#include "timer.hpp"
#include "player.hpp"
#include "wall.hpp"
#include "aiopponent.hpp"

const Uint32 FRAMES_PER_SEC = 30;

using namespace std;

SDL_Surface* screen;

int main ( int argc, char** argv )
{
	SDL_Event event;
	SDL_Surface* bg = SDL_LoadBMP("images/bg.bmp");
	SDL_Surface* vert=NULL;
	Player *player = new Player();
	Wall *wallv=new Wall(400,450,"images/building_01.png");
	Wall *wallx=new Wall(100,150,"images/building_02.png");
	Wall *wally=new Wall(20,500,"images/building_03.png");
	AiOpponent *granny = new AiOpponent(700,65,"images/granny64.png",900);
	AiOpponent *granny2= new AiOpponent(200,300,"images/granny64.png",70);
	AiOpponent *granny3= new AiOpponent(700,500,"images/granny64.png",70);
	vector<Model *> world;
	vector<Model *>::iterator it;
	vector<Model *> ai;
	vector<Model *>::iterator its;
	it = world.begin();
	its=ai.begin();
	its=ai.insert(its,granny);
	its=ai.insert(its,granny2);
	its=ai.insert(its,granny3);
	it = world.insert(it, wallv);
	it = world.insert(it, wallx);
	it = world.insert(it, wally);
	//    it=world.insert(it,granny);
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
	screen=SDL_SetVideoMode(1200,1024,32,SDL_HWSURFACE);
	SDL_WM_SetCaption("SHOЯTBUS","SHOЯTBUS");

	bool done = false;
	int frame = 0;
	Timer fps;
	fps.start();
	while(!done){

		// See http://en.wikipedia.org/wiki/Game_programming#Game_structure
		// Get user input.
		do{
			Uint8* keys= SDL_GetKeyState(NULL);
			if(!fps.isPaused())
				player->handleKeys(keys);

			if(event.type==SDL_QUIT){
				done = true;
			}

			if(event.type == SDL_KEYDOWN){
				if(keys[SDLK_ESCAPE]){
					done = true;
				}
				else if(keys[SDLK_SPACE]){
					if(fps.isPaused())
						fps.unpause();
				}
				else if(keys[SDLK_p])
					if(!fps.isPaused())
						fps.pause();
			}
		}while(SDL_PollEvent(&event));

		if(fps.isPaused())
			continue;

		// AI

		// move enemies
		// collisions
		player->getVehicle()->update(world);
		player->getVehicle()->checkAiCollisions(ai);
		// draw graphics
		//LEAVE THIS NEXT LINE HERE
		//granny->draw(screen,90);
		SDL_BlitSurface(bg,NULL,screen,NULL);
		wallv->draw(screen);
		wallx->draw(screen);
		wally->draw(screen);
		granny->update(ai);
		granny->draw(screen,90);
		granny2->draw(screen,90);
		granny3->draw(screen,90);
		player->drawVehicle(screen);

		if(SDL_Flip(screen) == -1)
			return 1;
		// play sounds

		// Increment frame counter
		frame ++;

		if(fps.getTicks() < 1000 / FRAMES_PER_SEC){
			SDL_Delay((1000/FRAMES_PER_SEC) - fps.getTicks());
		}
	}

	return 0;
}
