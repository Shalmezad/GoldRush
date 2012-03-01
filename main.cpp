#include "lib/Game.h"

int main ( int argc, char** argv )
{
    Game* m_game = new Game();
    m_game->run();
    delete(m_game);
    return 0;
}
