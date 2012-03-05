#include "Level.h"



Level::Level(sf::RenderWindow* app){
    App = app;
    currentState = LEVEL;
    m_Grid = new Grid();
    m_Background = new Background();
    m_Conveyor = new Conveyor();
    m_Held = new Held();
    m_Rocks = new Rocks();
    gameDone = false;
    explosionTick = 1;
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
    if(!gameDone){
        if(m_Conveyor->tick()){
            //Game over
            //currentState = EXIT;
            gameDone = true;
        }
    }
    render();
    if(gameDone){
        explosionTick += 3;
        if(explosionTick>=255){
            currentState = EXIT;
        }
    }
}

void Level::render(){
    //TODO: render the App window
}

void Level::handleEvents(){
    /*
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
                            currentState = LEVEL_CHANGE;
                        }
                    }
                }
            }
        }
    }
    */
    sf::Event Event;
    while(App->GetEvent(Event)){
        if(Event.Type == sf::Event::Closed){
            currentState = EXIT;
        }
        else if(Event.Type == sf::Event::KeyReleased){
            if(Event.Key.Code == sf::Key::Escape){
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
