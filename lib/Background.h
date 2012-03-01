#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include <SDL.h>
#include "Resource.h"


class Background{
public:
    Background();
    ~Background();
    void render(SDL_Surface* screen);
private:
    SDL_Surface* BG_Graphic;
};



#endif
