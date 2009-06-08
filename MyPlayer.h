#include <features.h>
#include <stdbool.h>
#include "AbstractPlayer.h"
#ifndef __MY_PLAYER_H__
#define __MY_PLAYER_H__
__BEGIN_DECLS

/**
 * @class MyPlayer
 * @implements AbstractPlayer
 */
typedef struct AbstractPlayer MyPlayer;

/**
 * @brief Use this to create object of MyPlayer.
 *
 * @return MyPlayer* The object instance of MyPlayer.
 * @retval NULL If it fails.
 */
MyPlayer* MyPlayer_create(void);

__END_DECLS
#endif //__MY_PLAYER_H__
