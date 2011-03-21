#ifndef PLAYSTATE_HPP_
#define PLAYSTATE_HPP_

#include <vector>

#include "gamestate.hpp"
#include "wall.hpp"
#include "aiopponent.hpp"
#include "player.hpp"

class PlayState: public GameState
{
public:
	PlayState(SDL_Surface *s);
	virtual void init();
	virtual bool update();
	virtual void draw(SDL_Surface *screen);
private:
    SDL_Event *event;
    SDL_Surface *bg;
    Player *player;
    Wall *wallA;
    Wall *wallB;
    Wall *wallC;
    AiOpponent *grannyA;
    AiOpponent *grannyB;
    AiOpponent *grannyC;
    vector<Model *> world;
    vector<Model *>::iterator it;
    vector<Model *> ai;
    vector<Model *>::iterator its;
};


#endif /* PLAYSTATE_HPP_ */
