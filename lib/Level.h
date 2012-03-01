#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <SDL.h>
#include "Subsystem.h"
#include "Grid.h"
#include "Background.h"

class Level:public Subsystem{
public:
    Level(SDL_Surface* s);
    ~Level();

    virtual void tick();
    virtual State checkState();
    virtual int stateParam();

private:
    State currentState;
    Grid* m_Grid;
    Background* m_Background;
    SDL_Surface* screen;

    void handleEvents();


};
#endif
