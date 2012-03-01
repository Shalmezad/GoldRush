#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <SDL.h>
#include "Subsystem.h"

class Level:public Subsystem{
public:
    Level();
    ~Level();

    virtual void tick(SDL_Surface* screen);
    virtual State checkState();
    virtual int stateParam();

private:




};
#endif
