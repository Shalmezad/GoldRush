#include "Rock.h"

SDL_Surface* Rock::bigrock1 = NULL;
SDL_Surface* Rock::bigrock2 = NULL;
SDL_Surface* Rock::smallrock1 = NULL;
SDL_Surface* Rock::smallrock2 = NULL;

void Rock::loadGraphics(){
    bigrock1 = Resource::loadGraphic("res/bigrock1.bmp");
    bigrock2 = Resource::loadGraphic("res/bigrock2.bmp");
    smallrock1 = Resource::loadGraphic("res/smallrock1.bmp");
    smallrock2 = Resource::loadGraphic("res/smallrock2.bmp");
}

void Rock::unloadGraphics(){
    SDL_FreeSurface(bigrock1);
    SDL_FreeSurface(bigrock2);
    SDL_FreeSurface(smallrock1);
    SDL_FreeSurface(smallrock2);
}

/*

    int type;
    int xgrid;
    int ygrid;
    int health;

    Rock(int t, int x, int y);
    void render(SDL_Surface* screen);
    bool crack(int x, int y);
    bool isAlive();

*/


Rock::Rock(int t, int x, int y){
    type = t;
    xgrid = x;
    ygrid = y;
    if(type == 1 || type == 2){
        health = 4;
    }
    else{
        health = 1;
    }
}

void Rock::render(SDL_Surface* screen){
    SDL_Rect pos;
    pos.x = 200 + xgrid*40;
    pos.y = 80 + ygrid * 40;
    switch(type){
        case 1:
            SDL_BlitSurface(bigrock1, NULL, screen, &pos);
            break;
        case 2:
            SDL_BlitSurface(bigrock2, NULL, screen, &pos);
            break;
        case 3:
            SDL_BlitSurface(smallrock1, NULL, screen, &pos);
            break;
        case 4:
            SDL_BlitSurface(smallrock2, NULL, screen, &pos);
            break;

    }
}

bool Rock::crack(int x, int y){
    if(type == 1 || type == 2){
        //means it could be in any of the 4 squares
        if((x == xgrid && y == ygrid) ||
           (x == xgrid + 1 && y == ygrid) ||
           (x == xgrid  && y == ygrid +1) ||
           (x == xgrid + 1 && y == ygrid+1)){
            health--;
            return true;
           }
    }
    else{
        if(x == xgrid && y == ygrid){
            health--;
            return true;
        }
    }
    return false;
}
bool Rock::isAlive(){
    if(health>0){
        return true;
    }
    else{
        return false;
    }
}
