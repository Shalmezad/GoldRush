#ifndef _BOMBGROUP_H_
#define _BOMBGROUP_H_

#include <vector>
#include <SDL.h>
#include <time.h>
#include "Bomb.h"
#include "Resource.h"


class Bombgroup{
public:
    Bombgroup(int type);
    ~Bombgroup();
    void render(SDL_Surface* screen);
    void render(SDL_Surface* screen, int x, int y);
    void renderOver(SDL_Surface* screen);
    void rotate();
    void move(int x, int y);
    int getX(){return xpos;}
    int getY(){return ypos;}
    bool checkCollision(int px, int py);
    std::vector<Bomb*> getBombs(){return bombs;}
private:
    int grouptype;
    int xpos, ypos;
    std::vector<Bomb*> bombs;
    void randomBomb();
    SDL_Surface* overgraphic;
    static bool seeded;

    static int round(double b);
};
#endif
