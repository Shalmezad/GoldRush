#ifndef _BOMBGROUP_H_
#define _BOMBGROUP_H_

#include <vector>
#include <SDL.h>
#include <time.h>
#include "Bomb.h"


class Bombgroup{
public:
    Bombgroup(int type);
    ~Bombgroup();
    void render(SDL_Surface* screen);
    void render(SDL_Surface* screen, int x, int y);
    void rotate();
    void move(int x, int y);
private:
    int grouptype;
    int xpos, ypos;
    std::vector<Bomb*> bombs;

    void randomBomb();
};
#endif
