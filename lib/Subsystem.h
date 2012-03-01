#ifndef _SUBSYSTEM_H_
#define _SUBSYSTEM_H_

#include <SDL.h>

    enum State{
        MAIN_MENU,
        LEVEL,
        HIGHSCORE,
        EXIT
    };

class Subsystem{
public:
    Subsystem();
    virtual void tick();
    virtual State checkState();
    virtual int stateParam();
};


#endif
