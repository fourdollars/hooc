#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MyPlayer.h"

static bool MyPlayer_open(MyPlayer* self, const char* url);
static bool MyPlayer_play(MyPlayer* self);
static bool MyPlayer_close(MyPlayer* self);

static const MyPlayer object_template = {
    .open  = MyPlayer_open,
    .play  = MyPlayer_play,
    .close = MyPlayer_close,
};

MyPlayer* MyPlayer_new(void)
{
    MyPlayer* self = malloc(sizeof(MyPlayer));
    if (self != NULL) {
        memcpy(self, &object_template, sizeof(MyPlayer));
    }
    return self;
}

bool MyPlayer_delete(MyPlayer* self)
{
    free(self);
    return true;
}

static bool MyPlayer_open(const char* url)
{
    printf("%s %s\n", __FUNCTION__, url);
    return true;
}

static bool MyPlayer_play(void)
{
    printf("%s\n", __FUNCTION__);
    return true;
}

static bool MyPlayer_close(void)
{
    printf("%s\n", __FUNCTION__);
    return true;
}
