#ifndef _GAME_H_
#define _GAME_H_

#include <SDL.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Subsystem.h"
#include "Level.h"
#include "Bomb.h"
#include "Rock.h"
#include "Score.h"

class Game{
public:
    Game();
    ~Game();
    void run();

private:
    sf::RenderWindow* App;
    SDL_Surface* screen;
    SDL_Surface* bmp;
    State currentState;
    Subsystem* currentSystem;
};



#endif
