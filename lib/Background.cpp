#include "Background.h"

Background::Background(){
    BG_Graphic = Resource::loadGraphic("res/background.bmp");
}

Background::~Background(){
    SDL_FreeSurface(BG_Graphic);
}

void Background::render(SDL_Surface* screen){
    SDL_BlitSurface(BG_Graphic, NULL, screen, NULL);
}
