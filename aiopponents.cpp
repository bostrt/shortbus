#include <SDL/SDL.h>
#include "aiopponents.hpp"
#include <string>
#include "model.hpp"
#include <vector>
using namespace std;

AiOponents::AiOponents(int x1,int y1, string filename, int pts):Model(x1,y1,filename){
	
	points=pts;
        

}
void AiOponents::update(std::vector<Model *> world){
//insert movement and deathcalls here

}
void AiOponents::die(){
//sends player added points and removes sprite
SDL_FreeSurface(image);

}

