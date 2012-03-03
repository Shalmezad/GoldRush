
#include "Grid.h"

Grid::Grid(){
    grid_graphic = Resource::loadGraphic("res/grid.bmp");
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            bombgrid[i][j] = 0;
        }
    }
    bombgrid[5][5] = 1;
    bombgrid[5][6] = 2;
    bombgrid[6][5] = 3;
    bombgrid[6][6] = 4;
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

void Grid::checkMatches(){
    bool matches[8][8];
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            matches[i][j] = false;
        }
    }

    //check horizontal matches
    for(int i=0; i<6; i++){
        for(int j=0; j<8; j++){
            if(bombgrid[i][j] != 0){
                if(bombgrid[i][j] == bombgrid[i+1][j] &&
                   bombgrid[i][j] == bombgrid[i+2][j]){
                    matches[i][j] = true;
                    matches[i+1][j] = true;
                    matches[i+2][j] = true;
                }
            }
        }
    }


    //check vertical matches
    for(int i=0; i<8; i++){
        for(int j=0; j<6; j++){
            if(bombgrid[i][j] != 0){
                if(bombgrid[i][j] == bombgrid[i][j+1] &&
                   bombgrid[i][j] == bombgrid[i][j+2]){
                    matches[i][j] = true;
                    matches[i][j+1] = true;
                    matches[i][j+2] = true;
                }
            }
        }
    }

    //for now, remove
    //TODO: use to remove rocks behind
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(matches[i][j]){
                bombgrid[i][j] = 0;
            }
        }
    }

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
