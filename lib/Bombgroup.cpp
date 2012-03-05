#include "Bombgroup.h"

bool Bombgroup::seeded = false;

Bombgroup::Bombgroup(int type){
    grouptype = type;
    xpos = 0;
    ypos = 0;
    if(!seeded){
        srand ( time(NULL) );
        seeded = true;
    }
    int numBombs;
    if(type == 1){
        numBombs = 1;
    }
    else if(type == 2 || type == 3 ){
        numBombs = 2;
    }
    else if(type == 4 || type == 5 || type == 6 || type == 7 || type == 8 || type == 9){
        numBombs = 3;
    }
    else if(type == 10){
        numBombs = 4;
    }
    for(int i=0; i<numBombs; i++){
        randomBomb();   //add random bomb to array
    }
    overgraphic.SetImage(Resource::loadGraphic("res/over.bmp"));
}

void Bombgroup::randomBomb(){
    int a = rand() % 3 + 1;
    Bomb* b = new Bomb(a);
    bombs.push_back(b);
}

bool Bombgroup::checkCollision(int px, int py){

    //need to go through each bomb position, and check to see if they collided
    bool flag = false;
    move(xpos, ypos);
    for(int a=0; a<bombs.size(); a++){
        int xpos = bombs[a]->getX();
        int ypos = bombs[a]->getY();
        //check to see if the point is in the bomb graphic
        if(px>xpos && px<(xpos+40)){
            if(py>ypos && py<(ypos+40)){
                flag = true;
            }
        }
    }
    return flag;
}

void Bombgroup::renderOver(sf::RenderWindow* App){
    for(int a=0; a<bombs.size(); a++){
        int x = bombs[a]->getX();
        int y = bombs[a]->getY();
        x = round(x/40.0) * 40.0;
        y = round(y/40.0) * 40.0;
        overgraphic.SetPosition(x,y);
        if(x>=200 && x<520){
            if(y>=80 && y<400){
                App->Draw(overgraphic);
            }
        }
    }

}


int Bombgroup::round(double b){
    double d = b;
    int c = d;
    d = d-c;
    if(d>=.5){
        return c + 1;
    }
    else{
        return c;
    }
}

void Bombgroup::rotate(){
    switch(grouptype){
        case 1:
            //single block, no need to do anything
            break;
        case 2:
            //group of 2 in line. 2->3
            grouptype = 3;
            break;
        case 3:
            //group of 2 in line. 3->2 with swap
            grouptype = 2;
            std::swap(bombs[0], bombs[1]);
            break;
        case 4:
            //group of 3 in line. 4->5
            grouptype = 5;
            break;
        case 5:
            //group of 3 in line, 5->4 with swap
            grouptype = 4;
            std::swap(bombs[0], bombs[2]);
            break;
        case 6:
            //group of 3 in L. 6->7
            grouptype = 7;
            break;
        case 7:
            //group of 3 in L. 7->8
            grouptype = 8;
            break;
        case 8:
            grouptype = 9;
            break;
        case 9:
            //group of 3 in L. 9->6, no swap necessary
            grouptype = 6;
            break;
        case 10:
            //group of 4 in "block". Must swap
            std::swap(bombs[0], bombs[3]);
            std::swap(bombs[1], bombs[2]);
            std::swap(bombs[0], bombs[2]);
            break;
    }
}

Bombgroup::~Bombgroup(){
    for(int a=0; a<bombs.size(); a++){
        delete(bombs[a]);
    }
}


void Bombgroup::move(int x, int y){
    xpos = x;
    ypos = y;
    switch(grouptype){
        case 1:
            bombs[0]->move(x,y);
            break;
        case 2:
            //line of 2 horizontally.
            bombs[0]->move(x,y);
            bombs[1]->move(x+40, y);
            break;
        case 3:
            //line of 2 vertically
            bombs[0]->move(x,y);
            bombs[1]->move(x,y+40);
            break;
        case 4:
            //line of 3 horizontally
            bombs[0]->move(x,y);
            bombs[1]->move(x+40, y);
            bombs[2]->move(x+80, y);
            break;
        case 5:
            //line of 3 vertically
            bombs[0]->move(x,y);
            bombs[1]->move(x,y+40);
            bombs[2]->move(x,y+80);
            break;
        case 6:
            //3 in L, no rotation
            bombs[0]->move(x,y);
            bombs[1]->move(x,y+40);
            bombs[2]->move(x+40,y+40);
            break;
        case 7:
            //3 in L, 90 rotation
            bombs[0]->move(x+40,y);
            bombs[1]->move(x,y);
            bombs[2]->move(x,y+40);
            break;
        case 8:
            //3 in L, 180 rotation
            bombs[0]->move(x+40,y+40);
            bombs[1]->move(x+40,y);
            bombs[2]->move(x,y);
            break;
        case 9:
            //3 in L, 270 rotation
            bombs[0]->move(x,y+40);
            bombs[1]->move(x+40,y+40);
            bombs[2]->move(x+40,y);
            break;
        case 10:
            //3 in L, 90 rotation
            bombs[0]->move(x,y);
            bombs[1]->move(x,y+40);
            bombs[2]->move(x+40,y+40);
            bombs[3]->move(x+40,y);
            break;

    }
}

void Bombgroup::render(sf::RenderWindow* App){
    render(App, xpos, ypos);
}

void Bombgroup::render(sf::RenderWindow* App, int x, int y){
    move(x,y);
    for(int a=0; a<bombs.size(); a++){
        bombs[a]->render(App);
    }
}

