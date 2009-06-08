#include "ObjectMacros.h"

#ifndef __MY_PLAYER_H__
#define __MY_PLAYER_H__
CPP_EXTERN_BEGIN

typedef struct _MyPlayer MyPlayer;

MyPlayer* MyPlayer_new(void);

bool MyPlayer_delete(MyPlayer* self);

struct _MyPlayer {
    void* _private;
    bool (*open)(MyPlayer* self, const char* url);
    bool (*play)(MyPlayer* self);
    bool (*close)(MyPlayer* self);
};

CPP_EXTERN_END
#endif //__MY_PLAYER_H__
