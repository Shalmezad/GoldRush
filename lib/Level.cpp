#include "Level.h"



Level::Level(SDL_Surface* s){
    screen = s;
    currentState = LEVEL;
    m_Grid = new Grid();
    m_Background = new Background();
    m_Conveyor = new Conveyor();
    m_Held = new Held();
    m_Rocks = new Rocks();
}

Level::~Level(){
    delete(m_Grid);
    delete(m_Background);
    delete(m_Conveyor);
    delete(m_Held);
    delete(m_Rocks);
}
void Level::tick(){
    handleEvents();
    m_Conveyor->tick();
    render();
}

void Level::render(){
    m_Background->render(screen);
    m_Rocks->render(screen);
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
            if(event.button.button == SDL_BUTTON_RIGHT ){
                m_Held->rotate();
            }
            if(event.button.button == SDL_BUTTON_LEFT){
                if(!m_Held->isHeld()){
                    Bombgroup* b;
                    b = m_Conveyor->checkClick(event.button.x, event.button.y);
                    if(b!=NULL){
                        m_Held->grab(b, event.button.x, event.button.y);
                    }
                }
            }
        }
        else if(event.type == SDL_MOUSEBUTTONUP){
            if(event.button.button == SDL_BUTTON_LEFT){
                if(m_Held->isHeld()){
                    if(m_Grid->play(m_Held->getGroup())){
                        m_Held->release();
                        bool done = m_Rocks->crack(m_Grid->checkMatches());
                        if(done){
                            currentState = EXIT;
                        }
                    }
                }
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
