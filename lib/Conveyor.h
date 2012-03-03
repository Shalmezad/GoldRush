#ifndef _CONVEYOR_H_
#define _CONVEYOR_H_

#include <SDL.h>
#include <vector>
#include <iostream>
#include "Bombgroup.h"
#include "Resource.h"

class Conveyor{
public:
    Conveyor();
    ~Conveyor();
    void render(SDL_Surface* screen);
    void tick();
    Bombgroup* checkClick(int xp, int yp);
private:
    SDL_Surface* down_graphic1;
    SDL_Surface* down_graphic2;
    SDL_Surface* down_graphic3;
    SDL_Surface* down_graphic4;

    SDL_Surface* right_graphic1;
    SDL_Surface* right_graphic2;
    SDL_Surface* right_graphic3;
    SDL_Surface* right_graphic4;

    std::vector<Bombgroup*> bombs;

    int anim_state;
    int anim_tick;
    int spawn_tick;
};
#endif
