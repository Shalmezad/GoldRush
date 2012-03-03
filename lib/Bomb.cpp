#include "Bomb.h"

SDL_Surface* Bomb::bomb1 = NULL;
SDL_Surface* Bomb::bomb2 = NULL;
SDL_Surface* Bomb::bomb3 = NULL;
SDL_Surface* Bomb::bomb4 = NULL;

Bomb::Bomb(int type){
    bombtype = type;
}

void Bomb::loadGraphics(){
    bomb1 = Resource::loadGraphic("res/bomb1.bmp");
    bomb2 = Resource::loadGraphic("res/bomb2.bmp");
    bomb3 = Resource::loadGraphic("res/bomb3.bmp");
    bomb4 = Resource::loadGraphic("res/bomb4.bmp");
}
void Bomb::unloadGraphics(){
    SDL_FreeSurface(bomb1);
    SDL_FreeSurface(bomb2);
    SDL_FreeSurface(bomb3);
    SDL_FreeSurface(bomb4);
}
void Bomb::render(SDL_Surface* screen, int x, int y){
    Bomb::render(bombtype, screen, x, y);
}
void Bomb::render(int type, SDL_Surface* screen, int x, int y){
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    if(type == 1){
        SDL_BlitSurface(bomb1, NULL, screen, &pos);
    }
    else if(type == 2){
        SDL_BlitSurface(bomb2, NULL, screen, &pos);
    }
    else if(type == 3){
        SDL_BlitSurface(bomb3, NULL, screen, &pos);
    }
    else if(type == 4){
        SDL_BlitSurface(bomb4, NULL, screen, &pos);
    }
}
