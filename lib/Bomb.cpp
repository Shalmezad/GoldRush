#include "Bomb.h"

Bomb::Bomb(int type){
    xpos = 0;
    ypos = 0;
    bombtype = type;
}

void Bomb::loadGraphics(){
    bombgraphic1.SetImage(Resource::loadGraphic("res/bomb1.bmp"));
    bombgraphic2.SetImage(Resource::loadGraphic("res/bomb2.bmp"));
    bombgraphic3.SetImage(Resource::loadGraphic("res/bomb3.bmp"));
    bombgraphic4.SetImage(Resource::loadGraphic("res/bomb4.bmp"));
}


void Bomb::render(int type, sf::RenderWindow* App, int x, int y){
    if(type == 1){
        bombgraphic1.SetPosition(x,y);
        App->Draw(bombgraphic1);
    }
    else if(type == 2){
        bombgraphic2.SetPosition(x,y);
        App->Draw(bombgraphic2);
    }
    else if(type == 3){
        bombgraphic3.SetPosition(x,y);
        App->Draw(bombgraphic3);
    }
    else if(type == 4){
        bombgraphic4.SetPosition(x,y);
        App->Draw(bombgraphic4);
    }
}

void Bomb::render(sf::RenderWindow* App){
    render(App, xpos, ypos);
}
void Bomb::render(sf::RenderWindow* App, int x, int y){
    xpos = x;
    ypos = y;
    Bomb::render(bombtype, App, x, y);
}
