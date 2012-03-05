#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics.hpp>
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
    Subsystem* currentSystem;
    State currentState;
};

#endif
