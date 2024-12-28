#ifndef __COMMON_H__
#define __COMMON_H__
#include<stddef.h>//size_t
extern void* my_malloc(size_t size);
extern void my_free(void* pointer);
#define MY_NEW(__TYPE__) \
    (__TYPE__*)my_malloc(sizeof(__TYPE__)) \
//
#endif//__COMMON_H__
