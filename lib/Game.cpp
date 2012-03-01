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


    currentState = LEVEL;
    currentSystem = new Level();


}

Game::~Game(){
}

void Game::run(){
    bool running = true;
    while(running){
        //run current subsystem
        currentSystem->tick();


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
