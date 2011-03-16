#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "model.hpp"

using namespace std;

class Vehicle: public Model{
protected:
    double velocity, direction;
public:
    Vehicle(double x, double y, string filename);
    void accelerate();
    void deccelerate();
    void turnRight();
    void turnLeft();
    virtual void update();
};

#endif
