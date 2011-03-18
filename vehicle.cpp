#include <string>
#include "vehicle.hpp"
#include "model.hpp"
#include "math.h"
#include "SDL_collide.h"
using namespace std;

/**
 * Constructor
 * Passed initial position and BMP.
 */
Vehicle::Vehicle(double x1, double y1, string filename):Model(x1, y1, filename)
{
    velocity=1;
    direction=0;
}

void Vehicle::accelerate(bool go)
{
    if(go){
        if(velocity<=2)
            velocity ++;
    }else{
        if(velocity>=2)
            velocity --;
        else
            velocity = 0;
    }
}

void Vehicle::reverse()
{
    if(velocity > -5)
        velocity--;
}

// Add to direction
void Vehicle::turnRight()
{
    if(direction < 0)
        direction = 360;
    direction -=2;
}

// Subtract from direction
void Vehicle::turnLeft()
{
    if(direction > 360)
        direction = 0;
    direction +=2;
}

// Update the vehicle's X and Y position
void Vehicle::update(Model* world[1])
{
   if(checkCollisions(world)){x=x;y=y;
    }
   else{
    double dx = (-velocity)* sin(direction*3.14/180);
    double dy = (-velocity)* cos(direction*3.14/180);
    x+=dx;
    y+=dy;}
}

/**
 * Getters and Setters
 */
double Vehicle::getVelocity(){
    return velocity;
}

double Vehicle::getDirection(){
    return direction;
}

void Vehicle::setVelocity(double v){
    velocity = v;
}

void Vehicle::setDirection(double d){
    direction = d;
}
bool Vehicle::checkCollisions(Model* world[1]){
int length=sizeof(world)/sizeof(Model);
for(int i=0;i<length;i++){
    if(SDL_CollidePixel(image,x,y,world[i]->getSurface(),world[i]->getX(),world[i]->getY(),4)!=0){
      return true;}
}
return false;



}




