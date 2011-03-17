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

#include <SDL/SDL.h>
#include <string>
//#include "SDL_rotozoom.h"
using namespace std;
class Model {
protected:
    double x, y;
    SDL_Rect boundingbox;
    SDL_Surface *image;
public:
    
    Model(double x, double y, string filename);
    void draw(SDL_Surface *screen,int rotation);
    void setX(double x1);
    void setY(double y1);
    double getX();
    double getY();
    virtual void update() = 0;
};

#endif
