#ifndef _ROCKS_H_
#define _ROCKS_H_

#include <vector>
#include "Rock.h"

class Rocks{
public:
    Rocks();
    void render(SDL_Surface* screen);
    bool crack(bool** bombgrid);
private:
    std::vector<Rock*> rockHolder;

};
#endif
