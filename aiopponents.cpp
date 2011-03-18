#include <SDL/SDL.h>
#include "aiopponents.hpp"
#include <string>
#include "model.hpp"
#include <vector>
#include <SDL/SDL_image.h>
#include <iostream>
#include "SDL_collide.h"
using namespace std;

AiOponents::AiOponents(int x1,int y1, string filename, int pts):Model(x1,y1,filename){
        flip=true;	
	points=pts;
       dead=false; 

}
void AiOponents::update(std::vector<Model *> world){
//insert movement and deathcalls here

if(!dead){
if(flip){
for(int i=0;i<world.size();i++){
//if(world[i]->getX()<0)flip=false;
int tempx=world[i]->getX();
tempx-=2;
world[i]->setX(tempx);
if(world[i]->getX()<0){flip=false;
}}}
else{
	for(int i=0;i<world.size();i++){
	  int tempx=world[i]->getX();
	  tempx+=10;
	  world[i]->setX(tempx);
	  if(world[i]->getX()>1024){
	  flip=true;
}
}}

checkCollisions();
}}
void AiOponents::die(Model* model){
//sends player added points and removes sprite
string filename="images/blood64.png";
SDL_Surface* tempimage=IMG_Load(filename.c_str());
//SDL_Rect dest;
//dest.x=image.x;
//dest.y=image.y;
model->setSurface(tempimage);
//SDL_BlitSurface(image,NULL,screen,&dest);
}
int AiOponents::getRotation(){}
void AiOponents::setRotation(int rotation){}
void AiOponents::checkCollisions()
{

}
