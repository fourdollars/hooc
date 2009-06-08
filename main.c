#include <stdio.h>
#include "MyPlayer.h"
#include "ChildPlayer.h"
#include "AbstractPlayer.h"
#include "ConcretePlayer.h"

int main(int argc, char* argv[])
{
    MyPlayer* player = NULL;
    ChildPlayer* child = NULL;
    AbstractPlayer* con = NULL;

    player = MyPlayer_new();
    player->open(player, "This is my player.");
    player->play(player);
    player->close(player);
    MyPlayer_delete(player);

    child = ChildPlayer_new();
    child->open(child, "This is Mr. Child.");
    child->play(child);
    child->close(child);
    ChildPlayer_delete(child);

    con = ConcretePlayer_create();
    con->open(con, "Abstract & Concrete");
    con->play(con);
    con->close(con);
    con->destroy(con);
    con = NULL;

    return 0;
}
