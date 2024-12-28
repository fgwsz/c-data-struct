#include<stdio.h>//printf
#include"ds_memory.h"//DS_ALLOC ds_free
static void _test_ds_memory(void){
    int* number_1=DS_ALLOC(int);
    int* number_2=ds_alloc(sizeof(int));
    printf("number_1{pointer:%p,value:%d}\n",number_1,*number_1);
    printf("number_2{pointer:%p,value:%d}\n",number_2,*number_2);
    *number_1=100;
    *number_2=100;
    printf("number_1{pointer:%p,value:%d}\n",number_1,*number_1);
    printf("number_2{pointer:%p,value:%d}\n",number_2,*number_2);
    ds_free(number_1);
    ds_free(number_2);
}
int main(void){
    _test_ds_memory();
    return 0;
}
