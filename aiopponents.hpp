#include <SDL/SDL.h>
#include <string>
#include "model.hpp"
#include <vector>
using namespace std;
class AiOponents:public Model{
public:
bool dead;
int getRotation();
void setRotation(int rotate);
bool flip;
int x,y,points;
SDL_Surface* image;
double velocity,direction;
AiOponents(int x,int y,string filename,int pts);
virtual void update(std::vector<Model *> world);
void die(Model* model);
};

