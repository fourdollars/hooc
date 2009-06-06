#include "ObjectMacros.h"

#ifndef __MY_PLAYER_H__
#define __MY_PLAYER_H__
C_OBJ_START

typedef struct _MyPlayer MyPlayer;

MyPlayer* MyPlayer_new(void);

bool MyPlayer_delete(MyPlayer* self);

struct _MyPlayer {
    bool (*open)(MyPlayer* self, const char* url);
    bool (*play)(MyPlayer* self);
    bool (*close)(MyPlayer* self);
};

C_OBJ_END
#endif //__MY_PLAYER_H__
