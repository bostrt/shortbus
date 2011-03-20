#include <SDL/SDL.h>
#include <string>
#include <vector>
#include <SDL/SDL_image.h>
#include <iostream>
#include <SDL/SDL_rotozoom.h>

#include "aiopponent.hpp"
#include "SDL_collide.h"

using namespace std;

AiOpponent::AiOpponent(int x1,int y1, string filename, int pts):Model(x1,y1,filename){
	flip = true;
	points = pts;
}
void AiOpponent::update(std::vector<Model *> world){
	//insert movement and deathcalls here

	for(int i=0;i<world.size();i++){
		if(((AiOpponent*)world[i])->isDead()==false){
			if(((AiOpponent*)world[i])->getDirection()==1){
				int tempx=world[i]->getX();
				tempx-=2;
				world[i]->setX(tempx);
				if(world[i]->getX()<0){
					((AiOpponent*)world[i])->setDirection(-1);
				}
			}
			else
			{
				int tempx=world[i]->getX();
				tempx+=2;
				world[i]->setX(tempx);
				if(((AiOpponent*)world[i])->getX()>1024){
					((AiOpponent*)world[i])->setDirection(1);
				}
			}
		}
	}

	checkCollisions(world);

}

void AiOpponent::die(Model* model){
	//sends player added points and removes sprite
	setDead(true);
	string filename="images/blood64.png";
	SDL_Surface* tempimage=IMG_Load(filename.c_str());
	SDL_Surface* temp2=rotozoomSurface(tempimage,points,1,0);
	model->setSurface(temp2);
}
int AiOpponent::getRotation(){

}
void AiOpponent::setRotation(int rotation){

}
void AiOpponent::checkCollisions(std::vector<Model *>worlds)
{

}
void AiOpponent::setDirection(int direction)
{
	dir=direction;
}
int AiOpponent::getDirection(){
	return dir;
}
void AiOpponent::setDead(bool deathstatus){
	dead=deathstatus;
}
bool AiOpponent::isDead(){
	return dead;
}
