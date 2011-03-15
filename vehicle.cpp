#include <string>
#include "vehicle.hpp"

using namespace std;

/**
 * Constructor
 * Passed initial position and BMP.
 */
Vehicle::Vehicle(double x1, double y1, string filename)
{
  // load image
  x = x1;
  y = y1;
}

/**
 * @param - 1 or -1. 1 is UP. -1 is DOWN.
 */
void Vehicle::dvelocity(int direction)
{
  if(direction == 1)
    accelerate();
  else if(direction == -1)
    deccelerate();
}

void Vehicle::accelerate()
{
  
}

void Vehicle::deccelerate()
{
  
}
