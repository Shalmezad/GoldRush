#ifndef _GAME_H_
#define _GAME_H_

#include <SDL.h>

class Game{
public:
    Game();
    void start();
private:
    SDL_Surface* screen;
    SDL_Surface* bmp;

};

#endif
