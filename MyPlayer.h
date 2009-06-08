#include <features.h>
#include <stdbool.h>
#ifndef __MY_PLAYER_H__
#define __MY_PLAYER_H__
__BEGIN_DECLS

typedef struct _MyPlayer MyPlayer;

MyPlayer* MyPlayer_new(void);

bool MyPlayer_delete(MyPlayer* self);

struct _MyPlayer {
    /**
     * @brief To keep some private data.
     */
    void* _private;
    /**
     * @brief 'open' function prototype
     *
     * @sa MyPlayer_open
     */
    bool (*open)(MyPlayer* self, const char* url);
    /**
     * @brief 'play' function prototype
     *
     * @sa MyPlayer_play
     */
    bool (*play)(MyPlayer* self);
    /**
     * @brief 'close' function prototype
     *
     * @sa MyPlayer_close
     */
    bool (*close)(MyPlayer* self);
};

__END_DECLS
#endif //__MY_PLAYER_H__
