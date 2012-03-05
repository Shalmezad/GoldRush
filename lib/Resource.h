#ifndef _RESOURCE_H_
#define _RESOURCE_H_

#include <SDL.h>
#include <SDL_image.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Resource{
public:
    static sf::Image loadGraphic(char* File);

};
#endif
