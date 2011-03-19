#ifndef MODEL_H
#define MODEL_H

#include <SDL/SDL.h>
#include <string>
#include <vector>

using namespace std;
class Model {
protected:
	double x, y;
	SDL_Surface *image;
public:
	SDL_Rect clip;
	void setSurface(SDL_Surface* surface);
	Model(int x, int y, string filename);
	void draw(SDL_Surface *screen,int rotation);
	void draw(SDL_Surface *screen);
	void setX(int x1);
	void setY(int y1);
	SDL_Surface* getSurface();
	int getX();
	int getY();
	virtual void update(std::vector<Model *> world) = 0;
};

#endif
