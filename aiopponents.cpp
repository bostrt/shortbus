#include <SDL/SDL.h>
#include "aiopponents.hpp"
#include <string>

using namespace std;

AiOponents::AiOponents(int x1,int y1, string filename, int pts){
	x=x1;
	y=y1;
	points=pts;
        char *cfilename;
        cfilename = new char[filename.length() + 1];
        strcpy(cfilename, filename.c_str());
        image=SDL_LoadBMP(cfilename);

}
void AiOponents::update(){
//insert movement and deathcalls here
}


