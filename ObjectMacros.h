#ifndef __OBJECT_MACROS_H__
#define __OBJECT_MACROS_H__
#ifdef __cplusplus
/* C++ extern */
#define CPP_EXTERN_BEGIN  extern "C" {
#define CPP_EXTERN_END    }
#else
#include <stdbool.h>
#define CPP_EXTERN_BEGIN
#define CPP_EXTERN_END
#endif
#endif //__OBJECT_MACROS_H__
