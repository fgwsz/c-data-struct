#include<stdlib.h>//malloc free
#include<string.h>//memset
#include"ds_memory.h"
//内存分配尝试的上限次数
#define _DS_ALLOC_TRY_COUNT 10
void* ds_alloc(size_t size){
    size=size==0?1:size;//size为0时尝试分配最小的内存块
    void* result=NULL;
    size_t count=0;
    //进行有限次内存分配尝试,全部失败之后返回NULL
    for(;count<_DS_ALLOC_TRY_COUNT;++count){
        result=malloc(size);
        if(result!=NULL){
            memset(result,0,size);
            break;
        }
    }
    return count<_DS_ALLOC_TRY_COUNT?result:NULL;
}
void ds_free(void* pointer){
    if(pointer!=NULL){
        free(pointer);
    }
}
