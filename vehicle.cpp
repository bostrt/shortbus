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
}

// Add to velocity
void Vehicle::accelerate()
{
    velocity ++;
}

// Subtract from velocity
void Vehicle::deccelerate()
{
    velocity --;
}

// Add to direction
void Vehicle::turnRight()
{
    if(direction > 360)
        direction = 0;
    direction ++;
}

// Subtract from direction
void Vehicle::turnLeft()
{
    if(direction < 0)
        direction = 360;
    direction --;
}

// Update the vehicle's X and Y position
void Vehicle::update()
{
    double dx = velocity* cos(direction);
    double dy = velocity* sin(direction);
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
