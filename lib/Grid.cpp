
#include "Grid.h"

Grid::Grid(){
    grid_graphic = Resource::loadGraphic("res/grid.bmp");
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            bombgrid[i][j] = 0;
        }
    }
    matchgrid = new bool*[8];
    for(int a=0; a<8; a++){
         matchgrid[a] = new bool[8];
         for(int b=0;b<8; b++){
            matchgrid[a][b] = false;
         }

    }
}

Grid::~Grid(){
    SDL_FreeSurface(grid_graphic);
}

void Grid::render(SDL_Surface* screen){
    SDL_Rect r;
    r.x = 200;
    r.y = 80;
    SDL_BlitSurface(grid_graphic,NULL, screen, &r);
    //render bombs
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            Bomb::render(bombgrid[i][j], screen, i*40 + 200, j*40 + 80);
        }
    }
}

int Grid::round(double b){
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

bool** Grid::checkMatches(){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            matchgrid[i][j] = false;
        }
    }

    //check horizontal matchgrid
    for(int i=0; i<6; i++){
        for(int j=0; j<8; j++){
            if(bombgrid[i][j] != 0){
                if(bombgrid[i][j] == bombgrid[i+1][j] &&
                   bombgrid[i][j] == bombgrid[i+2][j]){
                    matchgrid[i][j] = true;
                    matchgrid[i+1][j] = true;
                    matchgrid[i+2][j] = true;
                    Score::addScore(3);
                }
            }
        }
    }


    //check vertical matchgrid
    for(int i=0; i<8; i++){
        for(int j=0; j<6; j++){
            if(bombgrid[i][j] != 0){
                if(bombgrid[i][j] == bombgrid[i][j+1] &&
                   bombgrid[i][j] == bombgrid[i][j+2]){
                    matchgrid[i][j] = true;
                    matchgrid[i][j+1] = true;
                    matchgrid[i][j+2] = true;
                    Score::addScore(3);
                }
            }
        }
    }

    //for now, remove
    //TODO: use to remove rocks behind
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(matchgrid[i][j]){
                bombgrid[i][j] = 0;
            }
        }
    }
    return matchgrid;

}

bool Grid::play(Bombgroup* b){
    //TODO: check for matches if it was played.
    //should rely on level for this (if true, call Grid::checkMatches)

    bool flag = true; //can play until proven otherwise
    std::vector<Bomb*> bombs = b->getBombs();
    for(int a=0; a<bombs.size(); a++){
        //first, put all bombs in grid coordinates
        int x = bombs[a]->getX();
        int y = bombs[a]->getY();
        x = round(x/40.0) * 40;
        y = round(y/40.0) * 40;
        //bombs[a]->move(x,y);
        //now, see if they're in bounds
        if(x>=200 && x<520){
            if(y>=80 && y<400){
                //can continue
                //check if grid is taken
                x = (x-200)/40;
                y = (y-80)/40;
                if(bombgrid[x][y]!=0){
                    flag = false;
                    break;
                }
            }
            else{
                flag = false;
                break;
            }
        }
        else{
            flag = false;
            break;
        }
    }

    if(flag == true){
        //Copy bombs to grid
        for(int i = 0; i<bombs.size(); i++){
            //grab position
            int x = bombs[i]->getX();
            int y = bombs[i]->getY();
            x = round(x/40.0) * 40;
            y = round(y/40.0) * 40;
            //get relative x and y
            x = (x-200)/40;
            y = (y-80)/40;
            if(x>=0 && x<8 && y>=0 && y<8){
                bombgrid[x][y] = bombs[i]->getType();
            }
        }
        //since we ate the bomb group, delete it
        delete(b);
    }

    return flag;
}
