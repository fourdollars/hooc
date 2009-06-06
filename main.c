#include "MyPlayer.h"

int main(int argc, char* argv[])
{
    MyPlayer* player = MyPlayer_new();
    player.open("hello world");
    player.play();
    player.close();
    MyPlayer_delete(player);
}
