#include <stdlib.h>
#include <string.h>

#include "logger.h"
#include "MyPlayer.h"
#include "ChildPlayer.h"

/*
 * Functions Declaration
 */

static bool ChildPlayer_open(ChildPlayer* self, const char* url);
static bool ChildPlayer_play(ChildPlayer* self);
static bool ChildPlayer_close(ChildPlayer* self);

/*
 * Inner Utilities
 */

typedef struct _private_data private_data;

static inline private_data* get_data(ChildPlayer* self);
static inline MyPlayer* get_parent(ChildPlayer* self);

struct _private_data {
    MyPlayer* parent;
};

static const ChildPlayer object_template = {
    .open  = ChildPlayer_open,
    .play  = ChildPlayer_play,
    .close = ChildPlayer_close,
};

/*
 * Functions Definition
 */

static inline private_data* get_data(ChildPlayer* self)
{
    return (private_data*) self->_private;
}

static inline MyPlayer* get_parent(ChildPlayer* self)
{
    private_data* data = get_data(self);
    return data->parent;
}

ChildPlayer* ChildPlayer_new(void)
{
    logger_trace("%s", __FUNCTION__);
    ChildPlayer* self = malloc(sizeof(ChildPlayer));
    private_data* data = NULL;

    if (self == NULL) {
        logger_error("Memory not enough");
        return NULL;
    }

    memcpy(self, &object_template, sizeof(ChildPlayer));
    self->_private = malloc(sizeof(private_data));

    if (self->_private == NULL) {
        free(self);
        logger_error("Memory not enough");
        return NULL;
    }

    data = get_data(self);
    data->parent = MyPlayer_new();

    return self;
}

bool ChildPlayer_delete(ChildPlayer* self)
{
    logger_trace("%s", __FUNCTION__);
    MyPlayer* parent = get_parent(self);
    if (MyPlayer_delete(parent) == false) {
        logger_error("Error when MyPlayer_delete()");
    }
    free(self);
    return true;
}

static bool ChildPlayer_open(ChildPlayer* self, const char* url)
{
    logger_trace("%s %s", __FUNCTION__, url);
    MyPlayer* parent = get_parent(self);
    parent->open(parent, url);
    return true;
}

static bool ChildPlayer_play(ChildPlayer* self)
{
    logger_trace("%s", __FUNCTION__);
    MyPlayer* parent = get_parent(self);
    parent->play(parent);
    return true;
}

static bool ChildPlayer_close(ChildPlayer* self)
{
    logger_trace("%s", __FUNCTION__);
    MyPlayer* parent = get_parent(self);
    parent->close(parent);
    return true;
}
