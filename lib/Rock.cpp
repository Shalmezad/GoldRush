#include "Rock.h"

SDL_Surface* Rock::bigrock1_1 = NULL;
SDL_Surface* Rock::bigrock1_2 = NULL;
SDL_Surface* Rock::bigrock1_3 = NULL;
SDL_Surface* Rock::bigrock1_4 = NULL;
SDL_Surface* Rock::bigrock2_1 = NULL;
SDL_Surface* Rock::bigrock2_2 = NULL;
SDL_Surface* Rock::bigrock2_3 = NULL;
SDL_Surface* Rock::bigrock2_4 = NULL;
SDL_Surface* Rock::smallrock1 = NULL;
SDL_Surface* Rock::smallrock2 = NULL;

void Rock::loadGraphics(){
    bigrock1_1 = Resource::loadGraphic("res/bigrock1-1.bmp");
    bigrock1_2 = Resource::loadGraphic("res/bigrock1-2.bmp");
    bigrock1_3 = Resource::loadGraphic("res/bigrock1-3.bmp");
    bigrock1_4 = Resource::loadGraphic("res/bigrock1-4.bmp");
    bigrock2_1 = Resource::loadGraphic("res/bigrock2-1.bmp");
    bigrock2_2 = Resource::loadGraphic("res/bigrock2-2.bmp");
    bigrock2_3 = Resource::loadGraphic("res/bigrock2-3.bmp");
    bigrock2_4 = Resource::loadGraphic("res/bigrock2-4.bmp");
    smallrock1 = Resource::loadGraphic("res/smallrock1.bmp");
    smallrock2 = Resource::loadGraphic("res/smallrock2.bmp");
}

void Rock::unloadGraphics(){
    SDL_FreeSurface(bigrock1_1);
    SDL_FreeSurface(bigrock1_2);
    SDL_FreeSurface(bigrock1_3);
    SDL_FreeSurface(bigrock1_4);
    SDL_FreeSurface(bigrock2_1);
    SDL_FreeSurface(bigrock2_2);
    SDL_FreeSurface(bigrock2_3);
    SDL_FreeSurface(bigrock2_4);
    SDL_FreeSurface(smallrock1);
    SDL_FreeSurface(smallrock2);
}


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
            if(health==4)
                SDL_BlitSurface(bigrock1_1, NULL, screen, &pos);
            if(health==3)
                SDL_BlitSurface(bigrock1_2, NULL, screen, &pos);
            if(health==2)
                SDL_BlitSurface(bigrock1_3, NULL, screen, &pos);
            if(health==1)
                SDL_BlitSurface(bigrock1_4, NULL, screen, &pos);
            break;
        case 2:
            if(health==4)
                SDL_BlitSurface(bigrock2_1, NULL, screen, &pos);
            if(health==3)
                SDL_BlitSurface(bigrock2_2, NULL, screen, &pos);
            if(health==2)
                SDL_BlitSurface(bigrock2_3, NULL, screen, &pos);
            if(health==1)
                SDL_BlitSurface(bigrock2_4, NULL, screen, &pos);
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
