#include "Conveyor.h"

const int ANIM_DELAY = 5;

Conveyor::Conveyor(){
    down_graphic1 = Resource::loadGraphic("res/belt1-1.bmp");
    down_graphic2 = Resource::loadGraphic("res/belt1-2.bmp");
    down_graphic3 = Resource::loadGraphic("res/belt1-3.bmp");
    down_graphic4 = Resource::loadGraphic("res/belt1-4.bmp");

    anim_state = 1;
    anim_tick = 0;
}

Conveyor::~Conveyor(){
    SDL_FreeSurface(down_graphic1);
    SDL_FreeSurface(down_graphic2);
    SDL_FreeSurface(down_graphic3);
    SDL_FreeSurface(down_graphic4);
}

void Conveyor::render(SDL_Surface* screen){
    SDL_Rect belt1;
    belt1.x = 20;
    belt1.y = 0;
    if(anim_state == 1){
        SDL_BlitSurface(down_graphic1, NULL, screen, &belt1);
    }
    if(anim_state == 2){
        SDL_BlitSurface(down_graphic2, NULL, screen, &belt1);
    }
    if(anim_state == 3){
        SDL_BlitSurface(down_graphic3, NULL, screen, &belt1);
    }
    if(anim_state == 4){
        SDL_BlitSurface(down_graphic4, NULL, screen, &belt1);
    }
    anim_tick++;
    if(anim_tick>ANIM_DELAY){
        anim_tick = 0;
        anim_state ++;
        if(anim_state == 5){
            anim_state = 1;
        }
    }
}
