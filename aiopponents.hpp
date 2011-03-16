#include <SDL/SDL.h>
#include <string>
#include "model.hpp"
using namespace std;
class AiOponents:public Model{
public:
int x,y,points;
SDL_Surface* image;
double velocity,direction;
AiOponents(int x,int y,string filename,int pts);
void update();
void die();
};

