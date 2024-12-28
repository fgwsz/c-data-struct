#include<stdlib.h>//malloc free
#include<string.h>//memset
#define MY_MALLOC_RETRY_COUNT 10
void* my_malloc(size_t size){
    if(size==0){
        return NULL;
    }
    void* result=NULL;
    size_t count=0;
    for(;count<MY_MALLOC_RETRY_COUNT;++count){
        result=malloc(size);
        if(result!=NULL){
            memset(result,0,size);
            break;
        }
    }
    count<MY_MALLOC_RETRY_COUNT?result:NULL;
}
void my_free(void* pointer){
    if(pointer!=NULL){
        free(pointer);
    }
}
