#include <stdio.h>
#include "MyPlayer.h"
#include "ChildPlayer.h"
#include "AbstractPlayer.h"
#include "ConcretePlayer.h"

/**
 * @mainpage Object Oriented C Template
 *
 * @section intro_sec Introduction
 *
 * This is a template that attempts to implement Object Oriented C.
 *
 * You can see class @ref ConcretePlayer and interface @ref AbstractPlayer.
 *
 * Or class @ref MyPlayer and its subclass @ref ChildPlayer.
 *
 */

int main(int argc, char* argv[])
{
    MyPlayer* player = NULL;
    ChildPlayer* child = NULL;
    AbstractPlayer* con = NULL;

    player = MyPlayer_create();
    if (player->open(player, "This is my player.") == true) {
        player->play(player);
        player->close(player);
    }
    if (player->destroy(player) == true) {
        player = NULL;
    }

    child = ChildPlayer_create();
    if (child->open(child, "This is Mr. Child.") == true) {
        child->play(child);
        child->close(child);
    }
    if (child->destroy(child) == true) {
        child = NULL;
    }

    con = ConcretePlayer_create();
    if (con->open(con, "Abstract & Concrete") == true) {
        con->play(con);
        con->close(con);
    }
    if (con->destroy(con) == true) {
        con = NULL;
    }

    return 0;
}
