#ifndef _CONVEYOR_H_
#define _CONVEYOR_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Bombgroup.h"
#include "Resource.h"

class Conveyor{
public:
    Conveyor();
    ~Conveyor();
    void render(sf::RenderWindow* App);
    bool tick();
    Bombgroup* checkClick(int xp, int yp);
private:
    sf::Sprite down_graphic1;
    sf::Sprite down_graphic2;
    sf::Sprite down_graphic3;
    sf::Sprite down_graphic4;

    sf::Sprite right_graphic1;
    sf::Sprite right_graphic2;
    sf::Sprite right_graphic3;
    sf::Sprite right_graphic4;

    sf::Sprite endbox;

    std::vector<Bombgroup*> bombs;

    int anim_state;
    int anim_tick;
    int spawn_tick;
};
#endif
