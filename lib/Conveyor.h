#ifndef _CONVEYOR_H_
#define _CONVEYOR_H_

#include <SDL.h>
#include "Resource.h"

class Conveyor{
public:
    Conveyor();
    ~Conveyor();
    void render(SDL_Surface* screen);
private:
    SDL_Surface* down_graphic1;
    SDL_Surface* down_graphic2;
    SDL_Surface* down_graphic3;
    SDL_Surface* down_graphic4;
    int anim_state;
    int anim_tick;
};
#endif
