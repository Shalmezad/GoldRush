#include "Level.h"



Level::Level(SDL_Surface* s){
    screen = s;
    currentState = LEVEL;
    m_Grid = new Grid();
    m_Background = new Background();
    m_Conveyor = new Conveyor();
    m_Held = new Held();
}

Level::~Level(){
    delete(m_Grid);
    delete(m_Background);
    delete(m_Conveyor);
    delete(m_Held);
}
void Level::tick(){
    handleEvents();
    render();
}

void Level::render(){
    m_Background->render(screen);
    m_Grid->render(screen);
    m_Conveyor->render(screen);
    m_Held->render(screen);

    SDL_Flip(screen);

    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 220, 250));
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
        else if(event.type == SDL_MOUSEMOTION){
            m_Held->move(event.motion.x, event.motion.y);
        }
        else if(event.type == SDL_MOUSEBUTTONDOWN){
            if(event.button.button == SDL_BUTTON_LEFT ){
                m_Held->rotate();
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
