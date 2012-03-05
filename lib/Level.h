#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Subsystem.h"
#include "Grid.h"
#include "Background.h"
#include "Conveyor.h"
#include "Bomb.h"
#include "Held.h"
#include "Rocks.h"
#include "Score.h"
#include "Resource.h"

class Level:public Subsystem{
public:
    Level(sf::RenderWindow* app);
    ~Level();

    virtual void tick();
    virtual State checkState();
    virtual int stateParam();

private:
    sf::RenderWindow* App;
    State currentState;
    Grid* m_Grid;
    Background* m_Background;
    Conveyor* m_Conveyor;
    Held* m_Held;
    Rocks* m_Rocks;
    bool gameDone;
    int explosionTick;

    void handleEvents();
    void render();


};
#endif
