/**
 * Model
 * 
 * This is the base class for all items you will
 * see on screen.
 *
 * @author Robert Bost <bostrt at appstate dot edu>
 */

#ifndef MODEL_H
#define MODEL_H

class Model {
protected:
    double x, y, velocity, direction;
public:
    Model(double x, double y);
    void accelerate();
    void deccelerate();
    void turnRight();
    void turnLeft();
    void draw();
};

#endif
