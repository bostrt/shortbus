#include <string>
#include "vehicle.hpp"
#include "model.hpp"
#include "math.h"

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

// Add to velocity
void Vehicle::accelerate()
{
    if(velocity<=10)
        velocity --;
}

// Subtract from velocity
void Vehicle::deccelerate()
{
   if(velocity<=5)
        velocity ++;
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
void Vehicle::update()
{
    double dx = velocity* sin(direction*3.14/180);
    double dy = velocity* cos(direction*3.14/180);
    x+=dx;
    y+=dy;
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
