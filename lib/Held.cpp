#include "Held.h"

Held::Held(){
    xpos = 0;
    ypos = 0;
    grabbedx = 40;
    grabbedy = 40;
    heldGroup = NULL;
    holding = false;

}

void Held::move(int x, int y){
    xpos = x;
    ypos = y;
}
void Held::rotate(){
    if(holding){
        heldGroup->rotate();
    }
}

void Held::render(SDL_Surface* screen){
    if(holding){
        heldGroup->render(screen,xpos-grabbedx,ypos-grabbedy);
    }
}

void Held::grab(Bombgroup* b, int mx, int my ){
    if(b != NULL){
        holding = true;
        heldGroup = b;
        grabbedx = mx-heldGroup->getX();
        grabbedy = my-heldGroup->getY();
    }

}
