#ifndef _SCORE_H_
#define _SCORE_H_

#include <SDL.h>
#include <math.h>
#include "Resource.h"

class Score{
//note: displayed score is 10x regular score
public:
    static void loadGraphics();
    static void unloadGraphics();
    static void addScore(int a);
    static void render(SDL_Surface* screen);
private:
    static SDL_Surface* scoretext;
    static SDL_Surface* scoreback;
    static int score;

    static int getDigit(int num, int dig);
};

#endif
