#ifndef __OBJECT_MACROS_H__
#define __OBJECT_MACROS_H__
#ifdef __cplusplus
/* C++ extern */
#define C_OBJ_START  extern "C" {
#define C_OBJ_END    }
#else
#include <stdbool.h>
#define C_OBJ_START
#define C_OBJ_END
#endif
#endif //__OBJECT_MACROS_H__
