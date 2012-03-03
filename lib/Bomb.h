#ifndef _BOMB_H_
#define _BOMB_H_

#include <SDL.h>
#include "Resource.h"

class Bomb{
public:
    static void loadGraphics();
    static void unloadGraphics();

    Bomb(int type);
    /*void render(SDL_Surface* screen);*/
    void render(SDL_Surface* screen, int x, int y);
    static void render(int type, SDL_Surface* screen, int x, int y);

private:
    static SDL_Surface* bomb1;
    static SDL_Surface* bomb2;
    static SDL_Surface* bomb3;
    static SDL_Surface* bomb4;

    int bombtype;


};
#endif
