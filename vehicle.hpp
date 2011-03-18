#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <vector>
#include "model.hpp"

using namespace std;

class Vehicle: public Model{
protected:
    double velocity;
public:
    double direction;
    Vehicle(double x1, double y1, string filename);
    void accelerate(bool go);
    void reverse();
    void turnRight();
    void turnLeft();
    double getVelocity();
    double getDirection();
    void setVelocity(double v);
    void setDirection(double d);
    virtual void update(std::vector<Model *> world);
    bool checkCollisions(std::vector<Model *> world);
};

#endif
