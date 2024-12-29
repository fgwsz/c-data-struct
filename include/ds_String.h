#ifndef DS_STRING_H
#define DS_STRING_H

#define DS_STRING_DEFAULT_CAPACITY 10
typedef struct{
    char* data_;
    size_t capacity_;
    size_t size_;
}ds_string;
//初始化/赋值
bool ds_string_assign_char(ds_string* self,char value);
bool ds_string_assign_cstr(ds_string* self,char const* cstr);
bool ds_string_assign_str(ds_string* self,ds_string const* str);
bool ds_string_assign_cstr_range(ds_string* self,char const* cstr,size_t index,size_t count);
bool ds_string_assign_str_range(ds_string* self,ds_string const* str,size_t index,size_t count);

bool ds_string_assign_n_char(ds_string* self,size_t number,char value);
bool ds_string_assign_n_cstr(ds_string* self,size_t number,char const* cstr);
bool ds_string_assign_n_str(ds_string* self,size_t number,ds_string const* str);
bool ds_string_assign_n_cstr_range(ds_string* self,size_t number,char const* cstr,size_t index,size_t count);
bool ds_string_assign_n_str_range(ds_string* self,size_t number,ds_string const* str,size_t index,size_t count);
//销毁
bool ds_string_destory(ds_string const* self);
//读取属性
size_t ds_string_capacity(ds_string const* self);
size_t ds_string_size(ds_string const* self);
size_t ds_string_length(ds_string const* self);
bool ds_string_empty(ds_string const* self);
char* ds_string_get_cstr(ds_string* self);
char const* ds_string_get_const_cstr(ds_string const* self);
char ds_string_get_char(ds_string const* self,size_t index);
//修改属性
bool ds_string_set_char(ds_string* self,size_t index,char value);
bool ds_string_insert(ds_string* self,size_t position,ds_string const* str);
bool ds_string_append(ds_string* self,ds_string const* str);
bool ds_string_erase(ds_string* self,size_t index,size_t count);
//查找属性
size_t ds_string_find_first_of(ds_string* self,ds_string const* str);
size_t ds_string_find_last_of(ds_string* self,ds_string const* str);
//比较大小
int ds_string_compare(ds_string const* lhs,ds_string const* rhs);
//交换
bool ds_string_swap(ds_string* lhs,ds_string* rhs);
#endif//DS_STRING_H
