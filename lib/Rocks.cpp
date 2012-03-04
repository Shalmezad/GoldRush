#include "Rocks.h"

Rocks::Rocks(){

    Rock* c;
    for(int a=0; a<8; a++){
        for(int b=0; b<8; b++){
            if(a%2 == 0 && b%2 == 0){
                c = new Rock(1,a,b);
                rockHolder.push_back(c);
            }
        }
    }
}


void Rocks::render(SDL_Surface* screen){
    for(int a=0; a<rockHolder.size(); a++){
        rockHolder[a]->render(screen);
    }
}


bool Rocks::crack(bool** bombgrid){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(bombgrid[i][j]){
                //cycle through each of our rocks, IN REVERSE!
                for(int a=rockHolder.size()-1; a>=0; a--){
                    if(rockHolder[a]->crack(i,j)){
                        //check to see if it's alive
                        if(!rockHolder[a]->isAlive()){
                            rockHolder.erase(rockHolder.begin() + a);
                        }
                        break;
                    }
                }
            }
        }
    }
    if(rockHolder.size() > 0){
        return false;
    }
    return true;
}
