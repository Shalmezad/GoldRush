#ifndef _GRID_H_
#define _GRID_H_

#include <SDL.h>
#include <vector>
#include "Resource.h"
#include "Bomb.h"
#include "Bombgroup.h"

class Grid{
public:
    Grid();
    ~Grid();
    void render(SDL_Surface* screen);
    bool play(Bombgroup* b);
    void checkMatches();
private:
    int bombgrid[8][8];
    SDL_Surface* grid_graphic;

    int round(double b);

};
#endif
