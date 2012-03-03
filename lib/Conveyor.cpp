#include "Conveyor.h"

const int ANIM_DELAY = 5;

Conveyor::Conveyor(){
    down_graphic1 = Resource::loadGraphic("res/belt1-1.bmp");
    down_graphic2 = Resource::loadGraphic("res/belt1-2.bmp");
    down_graphic3 = Resource::loadGraphic("res/belt1-3.bmp");
    down_graphic4 = Resource::loadGraphic("res/belt1-4.bmp");

    right_graphic1 = Resource::loadGraphic("res/belt2-1.bmp");
    right_graphic2 = Resource::loadGraphic("res/belt2-2.bmp");
    right_graphic3 = Resource::loadGraphic("res/belt2-3.bmp");
    right_graphic4 = Resource::loadGraphic("res/belt2-4.bmp");



    anim_state = 1;
    anim_tick = 0;
}

Conveyor::~Conveyor(){
    SDL_FreeSurface(down_graphic1);
    SDL_FreeSurface(down_graphic2);
    SDL_FreeSurface(down_graphic3);
    SDL_FreeSurface(down_graphic4);

    SDL_FreeSurface(right_graphic1);
    SDL_FreeSurface(right_graphic2);
    SDL_FreeSurface(right_graphic3);
    SDL_FreeSurface(right_graphic4);
}

Bombgroup* Conveyor::checkClick(int xp, int yp){
    Bombgroup* temp = NULL;
    for(int a=0; a<bombs.size(); a++){
        if(bombs[a]->checkCollision(xp, yp)){
            //std::cout<<"click!\n";
            //it collided...
            temp = bombs[a];
            // erase the 6th element
            bombs.erase (bombs.begin()+a);
        }
    }
    return temp;
}


void Conveyor::tick(){
    //Move pieces
    for(int a=0; a<bombs.size(); a++){
        //need to move each piece
        int x = bombs[a]->getX();
        int y = bombs[a]->getY();
        if(y<440){
            y = y + 1;
        }
        else if(x<540){
            x = x + 1;
        }
        bombs[a]->move(x,y);
    }

    //Check to see if I spawn another
    spawn_tick++;
    if(spawn_tick>40){
        //check to make sure there are no other bombs close by
        bool flag = true;
        for(int a=0; a<bombs.size(); a++){
            if(bombs[a]->getY() < 100){
                flag = false;
            }
        }
        if(flag){
            spawn_tick = 0;
            Bombgroup* b = new Bombgroup( rand() % 10 + 1);
            b->move(40,-100);
            bombs.push_back(b);
        }
    }

}

void Conveyor::render(SDL_Surface* screen){
    //display belts
    SDL_Rect belt1;
    belt1.x = 20;
    belt1.y = 0;
    SDL_Rect belt2;
    belt2.x = 20;
    belt2.y = 420;
    if(anim_state == 1){
        SDL_BlitSurface(down_graphic1, NULL, screen, &belt1);
        SDL_BlitSurface(right_graphic1, NULL, screen, &belt2);
    }
    if(anim_state == 2){
        SDL_BlitSurface(down_graphic2, NULL, screen, &belt1);
        SDL_BlitSurface(right_graphic2, NULL, screen, &belt2);
    }
    if(anim_state == 3){
        SDL_BlitSurface(down_graphic3, NULL, screen, &belt1);
        SDL_BlitSurface(right_graphic3, NULL, screen, &belt2);
    }
    if(anim_state == 4){
        SDL_BlitSurface(down_graphic4, NULL, screen, &belt1);
        SDL_BlitSurface(right_graphic4, NULL, screen, &belt2);
    }
    anim_tick++;
    if(anim_tick>ANIM_DELAY){
        anim_tick = 0;
        anim_state ++;
        if(anim_state == 5){
            anim_state = 1;
        }
    }

    //display bomb groups
    for(int a=0; a<bombs.size(); a++){
        bombs[a]->render(screen);
    }

}
