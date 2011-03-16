#include <string>
#include "bus.hpp"
#include "vehicle.hpp"
#include <iostream>

SDL_Surface *screen;
void print(Vehicle *v);

// Use this thing for some testing
int main()
{
    Vehicle *v = new Bus(0, 0);
    print(v);
    v->accelerate();
    v->turnLeft();
    print(v);
    v->turnRight();
    print(v);
}

void print(Vehicle *v)
{
    cout << "Vel: " << v->getVelocity() << "\n";
    cout << "Dir: " << v->getDirection() << "\n";
}

