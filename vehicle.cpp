#include <string>
#include <iostream>
#include <vector>
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
void Vehicle::update(vector<Model *> world)
{
    if(!checkWallCollisions(world)){
        double dx = (-velocity)* sin(direction*3.14/180);
        double dy = (-velocity)* cos(direction*3.14/180);
        x+=dx;
        y+=dy;
    }
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

void Vehicle::checkAiCollisions(vector<Model *> ais){}

bool Vehicle::checkWallCollisions(std::vector<Model *> worlds)
{
    SDL_Surface *other = NULL;
    double otherX = 0;
    double otherY = 0;

    // Loop over all models in the world...
    for(int i = 0; i < worlds.size(); i++){
        other = worlds[i]->getSurface();
        otherX = worlds[i]->getX();
        otherY = worlds[i]->getY();
        SDL_SetClipRect(image, &clip);

        if(SDL_CollidePixel(other, otherX, otherY, image, x, y, 4) != 0){
            cout <<  otherX << "\n";
            cout <<  otherY << "\n\n";
            // If world is left of player then repell player to right
            if(otherX+other->w < (x+10)){
                x ++;
            }else if(otherX > x+clip.w){
                // repell left
                x --;
            }
            // If world is below player then repell player down
            if(otherY+other->h < (y+10)){
                y ++;
            }else if(otherY > y+clip.h){
                // repell up
                y --;
            }
            return true;
        }
    }
    return false;
}




