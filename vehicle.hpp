#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "model.hpp"

using namespace std;

class Vehicle: public Model{
protected:
    double velocity, direction;
public:
    Vehicle(double x1, double y1, string filename);
    void accelerate();
    void deccelerate();
    void turnRight();
    void turnLeft();
    double getVelocity();
    double getDirection();
    void setVelocity(double v);
    void setDirection(double d);
    virtual void update();
};

#endif
