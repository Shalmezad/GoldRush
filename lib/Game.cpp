#include "Game.h"


Game::Game(){


    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        throw "Could not initialize SDL";
    }

    screen = SDL_SetVideoMode(800, 600, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !screen )
    {
        throw "Unable to create the window";
    }

    SDL_WM_SetCaption("GoldRush",0);

    currentState = LEVEL;
    currentSystem = new Level(screen);

    Bomb::loadGraphics();
}

Game::~Game(){
    Bomb::unloadGraphics();
}

void Game::run(){
    bool running = true;
    while(running){
        //run current subsystem
        currentSystem->tick();
        SDL_Delay(20);

        //check to make sure nothing has changed...
        if(currentSystem->checkState()!=currentState){
            //means we need to change
            currentState = currentSystem->checkState();
            //TODO: change currentSystem to match current state
            //TODO: delete currentSystem before re-pointing pointer
            if(currentState == EXIT){
                running = false;
            }
        }
    }

    SDL_Quit();

}
