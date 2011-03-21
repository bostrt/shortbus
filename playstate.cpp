#include <SDL/SDL.h>
#include <iostream>

#include "playstate.hpp"
#include "timer.hpp"

PlayState::PlayState(SDL_Surface *s):GameState(s)
{
    
}

void PlayState::init()
{
    bg = SDL_LoadBMP("images/bg.bmp");
    player = new Player();
    wallA = new Wall(400,450,"images/building_01.png");
    wallB = new Wall(100,150,"images/building_02.png");
    wallC = new Wall(20,500,"images/building_03.png");
    grannyA = new AiOpponent(700,65,"images/granny64.png",900);
    grannyB = new AiOpponent(200,300,"images/granny64.png",70);
    grannyC = new AiOpponent(700,500,"images/granny64.png",70);
    event = new SDL_Event();
	it = world.begin();
	its = ai.begin();
	its = ai.insert(its,grannyA);
	its = ai.insert(its,grannyB);
	its = ai.insert(its,grannyC);
	it = world.insert(it, wallA);
	it = world.insert(it, wallB);
	it = world.insert(it, wallC);
}

bool PlayState::update()
{
    // See http://en.wikipedia.org/wiki/Game_programming#Game_structure
    // Get user input.
    do{
        Uint8* keys= SDL_GetKeyState(NULL);
        if(!fps->isPaused())
            player->handleKeys(keys);

        if(event->type == SDL_QUIT){
            return true;
        }

        if(event->type == SDL_KEYDOWN){
            if(keys[SDLK_ESCAPE]){
                return true;
            }
            else if(keys[SDLK_SPACE]){
                if(fps->isPaused())
                    fps->unpause();
            }
            else if(keys[SDLK_p])
                if(!fps->isPaused())
                    fps->pause();
        }
    }while(SDL_PollEvent(event));

    player->getVehicle()->update(world);
    grannyA->update(ai);
    player->getVehicle()->checkAiCollisions(ai);

    return false;
}

void PlayState::draw(SDL_Surface *screen)
{
    SDL_BlitSurface(bg,NULL,screen,NULL);
    wallA->draw(screen);
    wallB->draw(screen);
    wallC->draw(screen);
    grannyA->draw(screen);
    grannyB->draw(screen);
    grannyC->draw(screen);
    player->drawVehicle(screen);
}
