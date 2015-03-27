#include "sb6.h"
#include "Game.h"

int CALLBACK WinMain(HINSTANCE , HINSTANCE ,  LPSTR, int )                  
{            
    Game *game = new Game("Game Engine Demo", 800, 600);                                 
    game->Run();                                  
    return 0;                                       
}