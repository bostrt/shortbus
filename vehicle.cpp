#include <string>
#include "vehicle.hpp"
#include "model.hpp"
#include "math.h"

using namespace std;

/**
 * Constructor
 * Passed initial position and BMP.
 */
Vehicle::Vehicle(double x1, double y1, string filename):Model(x, y, filename)
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

void Vehicle::update()
{
    double dx = velocity* cos(direction);
    double dy = velocity* sin(direction);
    x+=dx;
    y+=dy;
}
