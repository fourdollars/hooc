#include <features.h>
#include <stdbool.h>
#ifndef __MY_PLAYER_H__
#define __MY_PLAYER_H__
__BEGIN_DECLS

/**
 * @class MyPlayer
 */
typedef struct MyPlayer MyPlayer;

/**
 * @brief Use this to create object of MyPlayer.
 *
 * @return MyPlayer* The object instance of MyPlayer.
 * @retval NULL If it fails.
 */
MyPlayer* MyPlayer_create(void);

struct MyPlayer {
    /** @cond */
    void* _private;
    /** @endcond */

    /** @cond */
    bool (*open)(MyPlayer* self, const char* url);
    /** @endcond */

    /** @cond */
    bool (*play)(MyPlayer* self);
    /** @endcond */

    /** @cond */
    bool (*close)(MyPlayer* self);
    /** @endcond */

    /** @cond */
    bool (*destroy)(MyPlayer* self);
    /** @endcond */
};

__END_DECLS
#endif //__MY_PLAYER_H__
