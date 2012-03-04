#include "Rocks.h"

Rocks::Rocks(){
    //make a boolean array to make sure every spot has a rock!
    bool hasRock[8][8];
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            hasRock[i][j] = false;
        }
    }

    //add big rocks
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            int a = rand() % 3 + 1;
            if(a == 1){
                a = rand()%2 + 1;
                Rock* temprock = new Rock(a,i,j);
                rockHolder.push_back(temprock);
                hasRock[i][j] = true;
                hasRock[i+1][j] = true;
                hasRock[i][j+1] = true;
                hasRock[i+1][j+1] = true;
            }
        }
    }

    //finally, small rocks
    //place them wherever there is no rock
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(!hasRock[i][j]){
                int a = rand() % 2 + 3;
                Rock* temprock = new Rock(a,i,j);
                rockHolder.push_back(temprock);
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
