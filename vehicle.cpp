#include <string>
#include <iostream>
#include <vector>

#include "vehicle.hpp"
#include "model.hpp"
#include "math.h"
#include "SDL_collide.h"
#include "aiopponent.hpp"

using namespace std;

/**
 * Constructor
 * Passed initial position and BMP.
 */
Vehicle::Vehicle(int x1, int y1, string filename):Model(x1, y1, filename)
{
	velocity=1;
	direction=0;
}

void Vehicle::accelerate(bool go)
{
	if(go){
		if(velocity<=10)
			velocity +=2;
	}else{
		if(velocity>=10)
			velocity --;
		else
			velocity = 0;
	}
}

void Vehicle::reverse()
{
	if(velocity > -5)
		velocity--;
}

// Add to direction
void Vehicle::turnRight()
{
	if(direction < 0)
		direction = 360;
	direction -=2;
}

// Subtract from direction
void Vehicle::turnLeft()
{
	if(direction > 360)
		direction = 0;
	direction +=2;
}

void Vehicle::reset()
{
	x = 400;
	y = 200;
	velocity = 0;
}

// Update the vehicle's X and Y position
void Vehicle::update(vector<Model *> world)
{
	if(!checkWallCollisions(world)){
		int dx = (-velocity)* sin(direction*3.14/180);
		int dy = (-velocity)* cos(direction*3.14/180);
		x+=dx;
		y+=dy;
	}
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

void Vehicle::checkAiCollisions(vector<Model *> ais)
{
	SDL_Surface *other = NULL;
	double otherX = 0;
	double otherY = 0;

	for(int i=0;i<ais.size();i++){
		other = ais[i]->getSurface();
		otherX = ais[i]->getX();
		otherY = ais[i]->getY();
		//SDL_SetClipRect(image, &clip);

		if(SDL_CollidePixel(other, otherX, otherY, image, x, y, 4) != 0){
			((AiOpponent*) ais[i])->die(ais[i]);
		}
	}
}

bool Vehicle::checkWallCollisions(std::vector<Model *> worlds)
{
	SDL_Surface *other = NULL;
	double otherX = 0;
	double otherY = 0;

	// Loop over all models in the world...
	for(int i = 0; i < worlds.size(); i++){
		other = worlds[i]->getSurface();
		otherX = worlds[i]->getX();
		otherY = worlds[i]->getY();
		//SDL_SetClipRect(image, &clip);

		if(SDL_CollidePixel(other, otherX, otherY, image, x, y, 4) != 0){
			cout << "COLLIDE: ";

			if(otherX > x){
				cout << "1\n";
				// repell left
				x --;
			}else if(x+20 > otherX+other->w){
				cout << "2\n";
				x ++;
			}

			if(otherY > y){
				cout << "A\n";
				// repell up
				y --;
			}else if(y+20 > otherY+other->h){
				cout << "B\n";
				y ++;
			}
			return true;
		}
	}
	return false;
}
