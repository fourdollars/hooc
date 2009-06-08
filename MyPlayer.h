#include <features.h>
#include <stdbool.h>
#ifndef __MY_PLAYER_H__
#define __MY_PLAYER_H__
__BEGIN_DECLS

typedef struct _MyPlayer MyPlayer;

MyPlayer* MyPlayer_new(void);

bool MyPlayer_delete(MyPlayer* self);

struct _MyPlayer {
    void* _private;
    bool (*open)(MyPlayer* self, const char* url);
    bool (*play)(MyPlayer* self);
    bool (*close)(MyPlayer* self);
};

__END_DECLS
#endif //__MY_PLAYER_H__
