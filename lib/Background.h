#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#include <SFML/Graphics.hpp>
#include "Resource.h"


class Background{
public:
    Background();
    ~Background();
    void render(sf::RenderWindow* App);
private:
    sf::Sprite bgSprite;
};



#endif
