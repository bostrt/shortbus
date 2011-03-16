#include <SDL/SDL.h>
#include <string>
using namespace std;
class AiOponents{
public:
int x,y,points;
SDL_Surface* image;
double velocity,direction;
AiOponents(int x,int y,string filename,int pts,int speedtype);
void update();
void die();
};

