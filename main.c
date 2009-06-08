#include <stdio.h>
#include "MyPlayer.h"
#include "ChildPlayer.h"

int main(int argc, char* argv[])
{
    MyPlayer* player = NULL;
    ChildPlayer* child = NULL;

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

    return 0;
}
