#include <features.h>
#include <stdbool.h>
#ifndef __ABSTRACT_PLAYER_H__
#define __ABSTRACT_PLAYER_H__
__BEGIN_DECLS

typedef struct _AbstractPlayer AbstractPlayer;

/**
 * @brief Abstract Player interface
 */
struct _AbstractPlayer {
    /**
     * @brief To keep some private data.
     */
    void* _private;
    /**
     * @brief 'open' function prototype
     *
     * @sa ConcretePlayer_open
     */
    bool (*open)(AbstractPlayer* self, const char* url);
    /**
     * @brief 'play' function prototype
     *
     * @sa ConcretePlayer_play
     */
    bool (*play)(AbstractPlayer* self);
    /**
     * @brief 'close' function prototype
     *
     * @sa ConcretePlayer_close
     */
    bool (*close)(AbstractPlayer* self);
    /**
     * @brief 'destroy' function prototype
     *
     * @sa ConcretePlayer_destroy
     */
    bool (*destroy)(AbstractPlayer* self);
};

__END_DECLS
#endif //__ABSTRACT_PLAYER_H__
