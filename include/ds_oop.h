#ifndef DS_OOP_H
#define DS_OOP_H
#define DS_CAST(TYPE__,...) ((TYPE__)(__VA_ARGS__))
struct ds_Object{
    void(*ctor_)(struct ds_Object* self);
    void(*dtor_)(struct ds_Object* self);
    void(*copy_)(struct ds_Object* to,struct ds_Object const* from);
    void(*swap_)(struct ds_Object* lhs,struct ds_Object* rhs);
};
extern void ds_Object_ctor(struct ds_Object* self);
extern void ds_Object_dtor(struct ds_Object* self);
extern void ds_Object_copy(struct ds_Object* to,struct ds_Object const* from);
extern void ds_Object_swap(struct ds_Object* lhs,struct ds_Object* rhs);

struct ds_Object* ds_Object_make(void){
    
    self->ctor_=&ds_Object_ctor;
    self->dtor_=&ds_Object_dtor;
    self->copy_=&ds_Object_copy;
    self->swap_=&ds_Object_swap;
}
void ds_Object_ctor(struct ds_Object* self){}
void ds_Object_dtor(struct ds_Object* self){}
void ds_Object_copy(struct ds_Object* to,struct ds_Object const* from){}
void ds_Object_swap(struct ds_Object* lhs,struct ds_Object* rhs){}

struct ds_Integer{
    struct ds_Object base_;
    long long value_;
};
extern void ds_Integer_ctor(struct ds_Object* self);
extern void ds_Integer_dtor(struct ds_Object* self);
extern void ds_Integer_copy(struct ds_Object* to,struct ds_Object const* from);
extern void ds_Integer_swap(struct ds_Object* lhs,struct ds_Object* rhs);
void ds_Integer_ctor(struct ds_Object* self){
    ds_Object_ctor(self);
    self->ctor_=&ds_Integer_ctor;
    self->dtor_=&ds_Integer_dtor;
    self->copy_=&ds_Integer_copy;
    self->swap_=&ds_Integer_swap;
    DS_CAST(struct ds_Integer*,self)->value_=0;
}
void ds_Integer_dtor(struct ds_Object* self){}
void ds_Integer_copy(struct ds_Object* to,struct ds_Object const* from){
    if(from==to){
        return;
    }
    DS_CAST(struct ds_Integer*,to)->value_=DS_CAST(struct ds_Integer*,from)->value_;
}
void ds_Integer_swap(struct ds_Object* lhs,struct ds_Object* rhs){
    if(lhs==rhs){
        return;
    }
    long long value=DS_CAST(struct ds_Integer*,lhs)->value_;
    DS_CAST(struct ds_Integer*,lhs)->value_=DS_CAST(struct ds_Integer*,rhs)->value_;
    DS_CAST(struct ds_Integer*,rhs)->value_=value;
}
#endif//DS_OOP_H
