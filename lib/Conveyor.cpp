#include "Conveyor.h"

const int ANIM_DELAY = 5;

Conveyor::Conveyor(){
    down_graphic1.SetImage(Resource::loadGraphic("res/belt1-1.bmp"));
    down_graphic2.SetImage(Resource::loadGraphic("res/belt1-2.bmp"));
    down_graphic3.SetImage(Resource::loadGraphic("res/belt1-3.bmp"));
    down_graphic4.SetImage(Resource::loadGraphic("res/belt1-4.bmp"));

    down_graphic1.SetPosition(20,0);
    down_graphic2.SetPosition(20,0);
    down_graphic3.SetPosition(20,0);
    down_graphic4.SetPosition(20,0);

    right_graphic1.SetImage(Resource::loadGraphic("res/belt2-1.bmp"));
    right_graphic2.SetImage(Resource::loadGraphic("res/belt2-2.bmp"));
    right_graphic3.SetImage(Resource::loadGraphic("res/belt2-3.bmp"));
    right_graphic4.SetImage(Resource::loadGraphic("res/belt2-4.bmp"));

    right_graphic1.SetPosition(20,420);
    right_graphic2.SetPosition(20,420);
    right_graphic3.SetPosition(20,420);
    right_graphic4.SetPosition(20,420);

    endbox.SetImage(Resource::loadGraphic("res/box.bmp"));

    endbox.SetPosition(520,420);

    spawn_tick = 0;
    anim_state = 1;
    anim_tick = 0;
}

Conveyor::~Conveyor(){
}

Bombgroup* Conveyor::checkClick(int xp, int yp){
    Bombgroup* temp = NULL;
    for(int a=bombs.size()-1; a>=0; a--){
        if(bombs[a]->checkCollision(xp, yp)){
            temp = bombs[a];
            bombs.erase (bombs.begin()+a);
        }
    }
    return temp;
}


bool Conveyor::tick(){
    bool dead = false;
    //Move pieces
    for(int a=0; a<bombs.size(); a++){
        //need to move each piece
        int x = bombs[a]->getX();
        int y = bombs[a]->getY();
        if(y<440){
            y = y + 1;
        }
        else if(x<540){
            x = x + 1;
        }
        //if any bomb goes into the box...
        if(x>=520){
            dead = true;
        }
        bombs[a]->move(x,y);
    }

    //Check to see if I spawn another
    spawn_tick++;
    if(spawn_tick>40){
        //check to make sure there are no other bombs close by
        bool flag = true;
        for(int a=0; a<bombs.size(); a++){
            if(bombs[a]->getY() < 100){
                flag = false;
            }
        }
        if(flag){
            spawn_tick = 0;
            Bombgroup* b = new Bombgroup( rand() % 10 + 1);
            b->move(40,-100);
            bombs.push_back(b);
        }
    }
    return dead;
}

void Conveyor::render(sf::RenderWindow* App){
    if(anim_state == 1){
        App->Draw(down_graphic1);
        App->Draw(right_graphic1);
    }
    if(anim_state == 2){
        App->Draw(down_graphic1);
        App->Draw(right_graphic1);
    }
    if(anim_state == 3){
        App->Draw(down_graphic1);
        App->Draw(right_graphic1);
    }
    if(anim_state == 4){
        App->Draw(down_graphic1);
        App->Draw(right_graphic1);
    }

    //TODO: move anim_tick to tick function...
    anim_tick++;
    if(anim_tick>ANIM_DELAY){
        anim_tick = 0;
        anim_state ++;
        if(anim_state == 5){
            anim_state = 1;
        }
    }


    App->Draw(endbox);

    //display bomb groups
    for(int a=0; a<bombs.size(); a++){
        bombs[a]->render(App);
    }

}
