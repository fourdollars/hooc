#include <stdlib.h>
#include <string.h>

#include "logger.h"
#include "MyPlayer.h"
#include "ChildPlayer.h"

/*
 * Functions Declaration
 */

/**
 * @brief ChildPlayer's open
 * @memberof ChildPlayer
 * @fn bool open(ChildPlayer* self, const char* url);
 *
 * @param self ChildPlayer's instance
 * @param url The target source.
 *
 * @return bool
 * @retval true If it works.
 * @retval false If it fails.
 */
static bool ChildPlayer_open(ChildPlayer* self, const char* url);

/**
 * @brief ChildPlayer's play
 * @memberof ChildPlayer
 * @fn bool play(ChildPlayer* self);
 *
 * @param self ChildPlayer's instance
 *
 * @return bool
 * @retval true If it works.
 * @retval false If it fails.
 */
static bool ChildPlayer_play(ChildPlayer* self);

/**
 * @brief ChildPlayer's close
 * @memberof ChildPlayer
 * @fn bool close(ChildPlayer* self);
 *
 * @param self ChildPlayer's instance
 *
 * @return bool
 * @retval true If it works.
 * @retval false If it fails.
 */
static bool ChildPlayer_close(ChildPlayer* self);

/**
 * @brief ChildPlayer's destroy
 * @memberof ChildPlayer
 * @fn bool destroy(ChildPlayer* self);
 *
 * @param self ChildPlayer's instance
 *
 * @return bool
 * @retval true If it works.
 * @retval false If it fails.
 */
static bool ChildPlayer_destroy(ChildPlayer* self);

/**
 * @brief ChildPlayer's pause
 * @memberof ChildPlayer
 * @fn bool pause(ChildPlayer* self);
 *
 * @param self ChildPlayer's instance
 *
 * @return bool
 * @retval true If it works.
 * @retval false If it fails.
 */
static bool ChildPlayer_pause(ChildPlayer* self);

/**
 * @brief ChildPlayer's setSpeed
 * @memberof ChildPlayer
 * @fn bool setSpeed(ChildPlayer* self, int speed);
 *
 * @param self ChildPlayer's instance
 * @param speed The speed of playback.
 *
 * @return bool
 * @retval true If it works.
 * @retval false If it fails.
 */
static bool ChildPlayer_setSpeed(ChildPlayer* self, int speed);

/*
 * Inner Utilities
 */

/** @cond */
typedef struct private_data private_data;
/** @endcond */

static inline private_data* get_data(ChildPlayer* self);
static inline MyPlayer* get_parent(ChildPlayer* self);

/** @cond */
struct private_data {
    MyPlayer* parent;
};
/** @endcond */

static const ChildPlayer object_template = {
    .open     = ChildPlayer_open,
    .play     = ChildPlayer_play,
    .close    = ChildPlayer_close,
    .destroy  = ChildPlayer_destroy,
    .pause    = ChildPlayer_pause,
    .setSpeed = ChildPlayer_setSpeed,
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

ChildPlayer* ChildPlayer_create(void)
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
    data->parent = MyPlayer_create();

    return self;
}

static bool ChildPlayer_destroy(ChildPlayer* self)
{
    logger_trace("%s", __FUNCTION__);
    MyPlayer* parent = get_parent(self);
    if (parent->destroy(parent) == false) {
        logger_error("Error when MyPlayer_delete()");
        return false;
    }
    free(self);
    return true;
}

static bool ChildPlayer_pause(ChildPlayer* self)
{
    logger_trace("%s", __FUNCTION__);
    MyPlayer* parent = get_parent(self);
    parent->pause(parent);
    return true;
}

static bool ChildPlayer_setSpeed(ChildPlayer* self, int speed)
{
    logger_trace("%s %d", __FUNCTION__, speed);
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
