#include "Subsystem.h"
Subsystem::Subsystem(){}
void Subsystem::tick(){};
State Subsystem::checkState() {return MAIN_MENU;};
int Subsystem::stateParam() {return 0;};
