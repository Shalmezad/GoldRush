#include "Level.h"



Level::Level(SDL_Surface* s){
    screen = s;
    currentState = LEVEL;
    m_Grid = new Grid();
    m_Background = new Background();
    m_Conveyor = new Conveyor();
}

Level::~Level(){
    delete(m_Grid);
}
void Level::tick(){
    handleEvents();

    m_Background->render(screen);
    m_Grid->render(screen);
    m_Conveyor->render(screen);
    SDL_Flip(screen);

}

void Level::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            currentState = EXIT;
        }
        else if(event.type == SDL_KEYDOWN){
            if(event.key.keysym.sym == SDLK_ESCAPE){
                currentState = EXIT;
            }
        }
    }
}

State Level::checkState(){
    return currentState;
}
int Level::stateParam(){
    return 0;
}
