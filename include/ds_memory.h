#ifndef DS_MEMORY_H
#define DS_MEMORY_H
#include<stddef.h>//size_t
//分配指定大小的置零的内存
//input@size:内存的字节数
//output:内存的地址
//  分配失败时,返回NULL
//  size为0时,返回非空的有效地址
extern void* ds_alloc(size_t size);
//释放指定地址的内存
//input@pointer:内存的地址
//  pointer为NULL时无操作
extern void ds_free(void* pointer);
//分配指定类型的置零的内存
//input@TYPE__:内存的类型
//output:内存的地址
//  分配失败时,返回NULL
//  sizeof(TYPE__)为0时,返回非空的有效地址
#define DS_ALLOC(TYPE__) (TYPE__*)ds_alloc(sizeof(TYPE__))
#endif//DS_MEMORY_H
