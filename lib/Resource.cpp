#include "Resource.h"

const int COLORKEY[] = {255,0,255};


SDL_Surface* Resource::loadGraphic(char* File){
    SDL_Surface* temp = NULL;
    SDL_Surface* ret = NULL;

    temp = IMG_Load(File);
    if(temp == NULL){
        return NULL;
    }

    ret = SDL_DisplayFormatAlpha(temp);
    SDL_FreeSurface(temp);


    //color key
    SDL_SetColorKey(ret, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(ret->format, COLORKEY[0], COLORKEY[1], COLORKEY[2]));

    return ret;

}
