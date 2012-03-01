#ifndef _GRID_H_
#define _GRID_H_

#include <SDL.h>

class Grid{
public:
    Grid();
    ~Grid();
    void render(SDL_Surface* screen);
private:
    SDL_Surface* grid_graphic;

};
#endif
