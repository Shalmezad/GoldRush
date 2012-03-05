#include "Resource.h"

sf::Image Resource::loadGraphic(char* file){
    sf::Image Image;
    Image.LoadFromFile(file);
    return Image;

}
