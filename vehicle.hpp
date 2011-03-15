#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

using namespace std;

class Vehicle{

private:
  void accelerate();
  void deccelerate();

public:
  Vehicle(double x, double y, string filename);
  double x, y;
  double velocity;
  double direction;
  void dvelocity(int direction);
};

#endif
