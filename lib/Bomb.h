#ifndef _BOMB_H_
#define _BOMB_H_

#include <SFML/Graphics.hpp>
#include "Resource.h"

class Bomb{
public:
    static void loadGraphics();
    static void render(int type, sf::RenderWindow* App, int x, int y);

    Bomb(int type);
    void render(sf::RenderWindow* App);
    void render(sf::RenderWindow* App, int x, int y);
    int getX(){return xpos;}
    int getY(){return ypos;}
    int getType(){return bombtype;}
    void move(int x, int y){xpos = x; ypos = y;}

private:
    static sf::Sprite bombgraphic1;
    static sf::Sprite bombgraphic2;
    static sf::Sprite bombgraphic3;
    static sf::Sprite bombgraphic4;

    int bombtype;
    int xpos;
    int ypos;

};
#endif
