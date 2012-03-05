#include "Background.h"

Background::Background(){
    bgSprite.SetImage(Resource::loadGraphic("res/background.bmp"));


}

Background::~Background(){
}

void Background::render(sf::RenderWindow* App){
    App->Draw(bgSprite);
}
