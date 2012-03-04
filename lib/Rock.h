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
    static SDL_Surface* bigrock1_1;
    static SDL_Surface* bigrock1_2;
    static SDL_Surface* bigrock1_3;
    static SDL_Surface* bigrock1_4;
    static SDL_Surface* bigrock2_1;
    static SDL_Surface* bigrock2_2;
    static SDL_Surface* bigrock2_3;
    static SDL_Surface* bigrock2_4;
    static SDL_Surface* smallrock1;
    static SDL_Surface* smallrock2;
    int type;
    int xgrid;
    int ygrid;
    int health;
};

#endif
