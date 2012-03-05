#include "Game.h"


Game::Game(){
    //Create the game window
    App->Create(sf::VideoMode(800, 600, 32), "GoldRush");
    currentState = LEVEL;
    currentSystem = new Level(App);
}

Game::~Game(){

}

void Game::run(){
    bool running = true;
    while(running){
        //run current subsystem
        currentSystem->tick();
        //Delay
        //TODO: lookup how to delay

        //check to make sure nothing has changed...
        if(currentSystem->checkState()!=currentState){
            //means we need to change
            currentState = currentSystem->checkState();
            if(currentState == LEVEL_CHANGE){
                delete currentSystem;
                currentSystem = new Level(App);
                currentState = LEVEL;
            }
            else if(currentState == EXIT){
                running = false;
            }
        }
    }


    App->Close();


}
