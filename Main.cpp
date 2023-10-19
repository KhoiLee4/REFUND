#include "stdafx.h"
#include "Game.h"
#include "Menu.h"

int main()
{
    //srand(static_cast<unsigned>(time(0)));

    /*Game game;
    while (game.getWindow().isOpen())
    {
        game.update();
        game.render();
    }*/
    //test loi commit
    Menu menu;
    menu.runMenu();

    //End of application
    return 0;
}