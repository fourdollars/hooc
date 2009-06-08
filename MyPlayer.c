#include <stdlib.h>
#include <string.h>

#include "logger.h"
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
    logger_trace("%s", __FUNCTION__);
    MyPlayer* self = malloc(sizeof(MyPlayer));

    if (self == NULL) {
        logger_error("Memory not enough");
        return NULL;
    }

    memcpy(self, &object_template, sizeof(MyPlayer));

    return self;
}

bool MyPlayer_delete(MyPlayer* self)
{
    logger_trace("%s", __FUNCTION__);
    free(self);
    return true;
}

static bool MyPlayer_open(MyPlayer* self, const char* url)
{
    logger_trace("%s %s", __FUNCTION__, url);
    return true;
}

static bool MyPlayer_play(MyPlayer* self)
{
    logger_trace("%s", __FUNCTION__);
    return true;
}

static bool MyPlayer_close(MyPlayer* self)
{
    logger_trace("%s", __FUNCTION__);
    return true;
}
