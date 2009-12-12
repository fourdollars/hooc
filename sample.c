#include <stdio.h>

#include "callback.h"

/*
 * user defined callback function
 */

typedef bool (*my_func_t)(const char*);

static bool funcA(const char*);
static bool funcB(const char*);
static bool funcC(const char*);

static bool my_cb_func(func_t func, va_list ap);

int main(int argc, char* argv[])
{
    list_t* list = NULL;

    add_func(&list, (func_t) funcA);
    add_func(&list, (func_t) funcB);
    add_func(&list, (func_t) funcC);

    invoke_all_func(&list, my_cb_func, "Hello World");
    remove_all_func(&list);

    return 0;
}

static bool my_cb_func(func_t func, va_list ap)
{
    my_func_t my_func = (my_func_t) func;
    const char* value = va_arg(ap, const char*);
    return my_func(value);
}

static bool funcA(const char* str)
{
    fprintf(stderr, "%s says %s\n", __FUNCTION__,  str);
    return true;
}

static bool funcB(const char* str)
{
    fprintf(stderr, "%s says %s\n", __FUNCTION__,  str);
    return true;
}

static bool funcC(const char* str)
{
    fprintf(stderr, "%s says %s\n", __FUNCTION__,  str);
    return true;
}
