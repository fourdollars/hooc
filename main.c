#include "MyPlayer.h"

int main(int argc, char* argv[])
{
    MyPlayer* player = MyPlayer_new();
    player->open(player, "hello world");
    player->play(player);
    player->close(player);
    MyPlayer_delete(player);
}
