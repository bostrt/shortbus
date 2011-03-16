#include <SDL/SDL.h>
#include "model.hpp"
#include "math.h"
extern SDL_Surface* screen;
// Constructor
Model::Model(double x1, double y1)
{
    x = x1;
    y = y1;
}


// Add to velocity
void Model::accelerate()
{
    velocity ++;
}

// Subtract from velocity
void Model::deccelerate()
{
    velocity --;
}

// Add to direction
void Model::turnRight()
{
    if(direction > 360)
        direction = 0;
    direction ++;
}

// Subtract from direction
void Model::turnLeft()
{
    if(direction < 0)
        direction = 360;
    direction --;
}
void Model::draw()
{
double dx = velocity* cos(direction);
double dy = velocity*sin(direction);
x+=dx;
y+=dy;
}
