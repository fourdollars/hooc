#include <features.h>
#include <stdbool.h>
#ifndef __CHILD_PLAYER_H__
#define __CHILD_PLAYER_H__
__BEGIN_DECLS

typedef struct _ChildPlayer ChildPlayer;

ChildPlayer* ChildPlayer_new(void);

bool ChildPlayer_delete(ChildPlayer* self);

struct _ChildPlayer {
    void* _private;
    bool (*open)(ChildPlayer* self, const char* url);
    bool (*play)(ChildPlayer* self);
    bool (*close)(ChildPlayer* self);
};

__END_DECLS
#endif //__CHILD_PLAYER_H__
