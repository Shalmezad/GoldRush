#ifndef _BOMBGROUP_H_
#define _BOMBGROUP_H_

#include <vector>
#include <SDL.h>
#include "Bomb.h"


class Bombgroup{
public:
    Bombgroup(int type);
    ~Bombgroup();
    void render(SDL_Surface* screen, int x, int y);
    void rotate();
private:
    int grouptype;
    std::vector<Bomb*> bombs;

    void randomBomb();
};
#endif
