#ifndef _HELD_H_
#define _HELD_H_

#include <SDL.h>
#include "Bombgroup.h"


class Held{
public:
    Held();
    void move(int x, int y);
    void render(SDL_Surface* screen);
    void rotate();
    void grab(Bombgroup* b, int mx, int my);
    bool isHeld(){return holding;}
private:
    int xpos;
    int ypos;
    int grabbedx;
    int grabbedy;
    Bombgroup* heldGroup;
    bool holding;
};

#endif
