#ifndef _BOMBGROUP_H_
#define _BOMBGROUP_H_

#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>
#include "Bomb.h"
#include "Resource.h"


class Bombgroup{
public:
    Bombgroup(int type);
    ~Bombgroup();
    void render(sf::RenderWindow* App);
    void render(sf::RenderWindow* App, int x, int y);
    void renderOver(sf::RenderWindow* App);
    void rotate();
    void move(int x, int y);
    int getX(){return xpos;}
    int getY(){return ypos;}
    bool checkCollision(int px, int py);
    std::vector<Bomb*> getBombs(){return bombs;}
private:
    int grouptype;
    int xpos, ypos;
    std::vector<Bomb*> bombs;
    void randomBomb();
    sf::Sprite overgraphic;
    static bool seeded;

    static int round(double b);
};
#endif
