#include "Score.h"

SDL_Surface* Score::scoretext = NULL;
SDL_Surface* Score::scoreback = NULL;
int Score::score = 0;

void Score::loadGraphics(){
    scoretext = Resource::loadGraphic("res/scoretext.bmp");
    scoreback = Resource::loadGraphic("res/scoreback.bmp");
}
void Score::unloadGraphics(){
    SDL_FreeSurface(scoretext);
    SDL_FreeSurface(scoreback);
}
void Score::addScore(int a){
    score = score + a;
}
void Score::render(SDL_Surface* screen){
    //now the fun part...
    SDL_Rect backPos;
    backPos.x = 206;
    backPos.y = 0;
    SDL_BlitSurface(scoreback, NULL, screen, &backPos);

    //and now, we get the digits
    SDL_Rect scoreDigit;
    scoreDigit.y = 0;
    scoreDigit.w = 36;
    scoreDigit.h = 80;
    SDL_Rect scorePos;
    scorePos.y = 10;
    for(int a=0; a<7; a++){
        int b = getDigit(score,a);
        //with the digit in hand...
        scoreDigit.x=b * 36;
        scorePos.x = (6-a)*36 + 216;
        SDL_BlitSurface(scoretext,&scoreDigit,screen,&scorePos);
    }
    scoreDigit.x = 0;
    scorePos.x = 7*36 + 216;
    SDL_BlitSurface(scoretext,&scoreDigit,screen,&scorePos);
}

int Score::getDigit(int num, int digit){
	int temp;
	temp = num/(pow(10,digit));
	temp = temp % 10;
	return temp;
}
