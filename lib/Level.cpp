#include "Level.h"



Level::Level(){


}

Level::~Level(){

}
void Level::tick(SDL_Surface* screen){

}
State Level::checkState(){
    return MAIN_MENU;
}
int Level::stateParam(){
    return 0;
}
