
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

bool Grid::play(Bombgroup* b){
    delete(b);
    return true;
}
