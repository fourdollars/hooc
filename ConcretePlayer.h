#include <features.h>
#include <stdbool.h>
#include "AbstractPlayer.h"
#ifndef __CONCRETE_PLAYER_H__
#define __CONCRETE_PLAYER_H__
__BEGIN_DECLS

typedef struct _AbstractPlayer ConcretePlayer;

ConcretePlayer* ConcretePlayer_create(void);

__END_DECLS
#endif //__CONCRECTE_PLAYER_H__
