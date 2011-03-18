#include <SDL/SDL.h>
#include "aiopponents.hpp"
#include <string>
#include "model.hpp"
#include <vector>
#include <SDL/SDL_image.h>
using namespace std;

AiOponents::AiOponents(int x1,int y1, string filename, int pts):Model(x1,y1,filename){
	
	points=pts;
        

}
void AiOponents::update(std::vector<Model *> world){
//insert movement and deathcalls here
for(int i=0;i<world.size();i++){
int tempx=world[i]->getX();
tempx--;
world[i]->setX(tempx);
}
}
void AiOponents::die(){
//sends player added points and removes sprite
image=IMG_Load("images/blood64.png");

}

