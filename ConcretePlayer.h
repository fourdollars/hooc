#include <features.h>
#include <stdbool.h>
#include "AbstractPlayer.h"
#ifndef __CONCRETE_PLAYER_H__
#define __CONCRETE_PLAYER_H__
__BEGIN_DECLS

/**
 * @class ConcretePlayer
 * @implements AbstractPlayer
 */
typedef AbstractPlayer ConcretePlayer;

/**
 * @brief Use this to create object of ConcretePlayer.
 *
 * @return ConcretePlayer* The object instance of ConcretePlayer.
 * @retval NULL If it fails.
 */
ConcretePlayer* ConcretePlayer_create(void);

__END_DECLS
#endif //__CONCRECTE_PLAYER_H__
