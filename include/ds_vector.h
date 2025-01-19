#ifndef DS_VECTOR_H
#define DS_VECTOR_H
#include<stddef.h>//size_t
typedef struct Vector{
    void** data_;
    size_t capacity_;
    size_t size_;
}ds_vector;
#define DS_VECTOR_DEFAULT_CAPACITY 10
int ds_vector_insert(ds_vector* self,size_t position,void* value);
int ds_vector_erase(ds_vector* self,size_t position);
int ds_vector_set(ds_vector* self,size_t position,void* value);
void* ds_vector_get(ds_vector* self,size_t position);
void* ds_vector_foreach(
    ds_vector* self
    ,size_t begin
    ,size_t end
    ,void*(*function)(void*)
);
#endif//DS_VECTOR_H
