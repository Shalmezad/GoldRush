#ifndef _ROCK_H_
#define _ROCK_H_

#include <SDL.h>
#include "Resource.h"

class Rock{
public:
    Rock(int t, int x, int y);
    void render(SDL_Surface* screen);
    bool crack(int x, int y);
    bool isAlive();

    static void loadGraphics();
    static void unloadGraphics();

private:
    static SDL_Surface* bigrock1;
    static SDL_Surface* bigrock2;
    static SDL_Surface* smallrock1;
    static SDL_Surface* smallrock2;
    int type;
    int xgrid;
    int ygrid;
    int health;
};

#endif
