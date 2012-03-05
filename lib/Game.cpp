#include "Game.h"


Game::Game(){
    App->Create(sf::VideoMode(800, 600, 32), "SFML Graphics");
    currentState = LEVEL;
    currentSystem = new Level(App);

    Bomb::loadGraphics();
    Rock::loadGraphics();
    Score::loadGraphics();
}

Game::~Game(){
    Bomb::unloadGraphics();
    Rock::unloadGraphics();
    Score::unloadGraphics();
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
            if(currentState == LEVEL_CHANGE){
                delete currentSystem;
                currentSystem = new Level(App);
                currentState = LEVEL;
            }
            else if(currentState == EXIT){
                running = false;
            }
        }
        //but, just because it's the same...
    }

    SDL_Quit();

}
