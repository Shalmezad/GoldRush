
#include "Grid.h"

Grid::Grid(){
    grid_graphic = Resource::loadGraphic("res/grid.bmp");
}

Grid::~Grid(){
    SDL_FreeSurface(grid_graphic);
}

void Grid::render(SDL_Surface* screen){
    SDL_Rect r;
    r.x = 200;
    r.y = 80;
    SDL_BlitSurface(grid_graphic,NULL, screen, &r);

}
