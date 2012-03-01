#include "Subsystem.h"
Subsystem::Subsystem(){}
void Subsystem::tick(SDL_Surface* screen){};
State Subsystem::checkState() {return MAIN_MENU;};
int Subsystem::stateParam() {return 0;};
