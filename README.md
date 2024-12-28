# 数据结构(C语言实现)
## 项目规范
### 文件存放
`头文件`存放到`include/`目录下.  
`源文件`存放到`source/`目录下.  
`测试文件`存放到`test/`目录下.  
```txt
include/
    hello.h
source/
    hello.c
test/
    main.c
```
### 命名空间
命名空间为`ds`,`ds`是`data-structure`的缩写.  
### 文件命名
文件名命名采取蛇形命名法,使用小写字母,使用下划线隔开每个单词.  
文件名使用`ds_`作为开头的,代表属于命名空间`ds`下的文件.  
```txt
include/
    ds_xxx.h
source/
    ds_xxx.c
```
### 编码规范
#### 宏
`宏`采用全部大写的方式来命名,使用下划线隔开每个单词.  
```c
#define DS_EMPTY
```
访问权限为`private`的宏采用一个下划线`_`作为开头.  
```c
#define _DS_STR(...) #__VA_ARGS__
```
`宏函数的参数列表中的形式参数`采用全部大写的方式来命名,  
```c
#define DS_CAST(TYPE__,...) ((TYPE__)(__VA_ARGS__))
```
使用下划线隔开每个单词,使用两个下划线`__`作为结尾.  
`头文件保护宏`采用文件名全部大写的方式来命名,文件名中的下划线保留,  
文件的后缀名`.h`用`_H`替代.  
举例:`ds_xxx.h`的`头文件保护宏`正确书写方式如下:  
```c
#ifndef DS_XXX_H
#define DS_XXX_H

#endif//DS_XXX_H
```
#### 类(`struct/union/enum`)
`struct/union/enum`的命名都是采用大驼峰的命名方式.  
```c
struct DynamicArray;
union DataType;
enum TypeInfo;
```
在命名空间`ds`下的类使用`ds_`作为名称的前缀.  
```c
struct ds_DynamicArray;
union ds_DataType;
enum ds_TypeInfo;
```
访问权限为`private`的类采用一个下划线`_`作为开头.  
```c
struct _DynamicArray;
union _DataType;
enum _TypeInfo;
struct _ds_DynamicArray;
union _ds_DataType;
enum _ds_TypeInfo;
```
`枚举值`  
命名规则与宏保持一致.  
`类书写与访问权限`  
类分为按照访问权限分为`public`类和`private`类,  
为了充分利用`C`语言的封装性,制定如下规定:  
1. 在头文件中只写`struct/union`的类声明,不写`struct/union`的类实现.  
2. 只在源文件中写`struct/union`的类实现.  
3. 可以在头文件/源文件中写`enum`的声明和实现.  
#### 类型别名
类型别名采用蛇形命名法,使用小写字母,使用下划线隔开每个单词.  
```c
typedef struct Xyx xyz;
typedef struct ds_Xyx ds_xyz;
```
#### 函数
`普通函数`的命名方式采用蛇形命名法,使用小写字母,使用下划线隔开每个单词.  
```c
void say_hello(void);
```
`类成员函数`的命名方式采用如下格式:  
`[struct name]_[function name]`  
其中`[struct name]`展开为函数所属的结构体的名称,  
其中`[function name]`展开为函数实现功能的名称.  
```c
struct ds_String;
size_t ds_String_length(struct ds_String const* self);
```
`函数书写与访问权限`  
函数分为按照访问权限分为`public`函数和`private`函数,  
分别对应函数声明的`extern`和`static`.  
为了充分利用`C`语言的封装性,制定如下规定:  
1. 在头文件中只写带有`extern`标识符的`public`函数的函数声明,  
不写带有`static`标识符的`private`函数的函数声明以及任何函数的实现(函数体).  
2. 只在源文件中写带有`static`标识符的`private`函数的函数声明以及函数实现.  
如果`private`函数的函数声明和函数实现是分开写的,  
那么在写函数实现时省略`static`标识符.  
3. 只在源文件中写声明带有`extern`标识符的`public`函数的函数实现,  
在写函数实现时省略`extern`标识符.  
4. `private`函数的函数名采用一个下划线`_`作为开头.  
```c
//impl.c
static void _func(void);
void _func(void){
    //TODO
}
```
#### 变量
`普通变量`的命名方式采用蛇形命名法,使用小写字母,使用下划线隔开每个单词.  
```c
size_t index_of_array=0;
```
`类成员变量`的命名方式采用蛇形命名法,使用小写字母,使用下划线隔开每个单词,  
使用一个下划线`_`作为结尾.  
```c
struct ds_LinkedNode{
    struct ds_LinkedNode* next_;
    void* data_;
};
```
#### 注释
注释只在必要的地方进行注释,只使用`//`单行注释.  
有必要的地方主要有2处:  
1. 头文件中的接口声明  
2. 源文件中复杂逻辑的关键实现步骤  
3. `#include`导入的头文件中被引用的接口信息  
```c
#include<stddef.h>//size_t
```

头文件的接口声明主要是对函数进行注释,为规范函数注释,制定如下规则:  
```c
//函数功能的简要说明
//input@arg1:函数第1个参数的说明
//input@arg2:函数第2个参数的说明
//...
//input@argN:函数第N个参数的说明
//output:函数返回值的说明(当返回值类型为void时,可以不写这一项)
//一些使用过程中的注意事项
extern int func(int arg1,double arg2,...);
```
