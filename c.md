
## 数组  
   1. 数组名是指向数组第一个元素的指针。  
   2. 数组名作为函数参数传递其实是传递数组首地址。  
   3. 多维数组作为函数参数传递，要指明第二位及接下来所有维的size。  
   
## Keywords: 
- typedef
- volatile
- const
- void

### typedef
usage:
   1. 指针
   2. 结构体
   3. 函数指针
```cpp
    // usage 1
    typedef int* Pointer;
    Pointer a, b;
    
    // usage 2
    typedef struct _a {
       // ;
    } A;
    A a, b;
    
    // usage 3
    typedef void (*func)(int, int);
    func a, b; 
```
### volatile
volatile 告诉编译器变量是随时可能发生变化的，每次使用它的时候必须从内存地址中读取，而不是从寄存器读取。
1) 并行设备的硬件寄存器（如：状态寄存器） 
2) 一个中断服务子程序中会访问到的非自动变量(Non-automatic variables) 
3) 多线程应用中被几个任务共享的变量。   
4）和编译器优化选项有关系  
__从内存里重新load 从而避免被 CPU register Cache!!!__

### void及void指针

void即“无类型”，void *则为“无类型指针”，可以指向任何数据类型。

void指针使用规范
①void指针可以指向任意类型的数据，亦即可用任意数据类型的指针对void指针赋值。例如：
int * pint;
void *pvoid;
pvoid = pint; /* 不过不能 pint= pvoid; */
如果要将pvoid赋给其他类型指针，则需要强制类型转换如：pint= (int *)pvoid;

在ANSIC标准中，不允许对void指针进行算术运算如pvoid++或pvoid+=1等，而在GNU中则允许，因为在缺省情况下，GNU认为void *与char *一样。sizeof(*pvoid )== sizeof( char).

void指针只有地址没有类型 
   - int *p -> void* p 把地址给void指针
   - void *p -> int* p 需要提供类型信息，没有->出错

void的作用
①对函数返回的限定。  
②对函数参数的限定。  
当函数不需要返回值时，必须使用void限定。例如： void func(int, int);  
当函数不允许接受参数时，必须使用void限定。例如： int func(void)。  

由于void指针可以指向任意类型的数据，亦即可用任意数据类型的指针对void指针赋值，因此还可以用void指针来作为函数形参，这样函数就可以接受任意数据类型的指针作为参数。例如：
void * memcpy( void *dest, const void *src, size_t len );


### 指针：
-数组指针 - int (* p)[10]  
-指针数组 - int * p[10]  
-函数指针 - int (* p)(int)  
-函数指针数组 - int (*p[])(int)  
-指针函数 - 返回值为指针的函数  

int a[2][3] = {1,2,3,4,5,6,7,8,9} a type - int (int*)[2]
二维数组指针是数组指针类型： 访问元素 *(*(a + 1) + 1)

### constant

const int a; - a为 constant int  
int const a; - 同上   
const int *a; - 指针的值为 constant   
int const *a; - 指针的值为 constant   
int * const a; - 指针 constant  
int const * a const; - 指针和值都为constant  
int fn(int a, int b) const - cpp 一个类中任何不会修改数据成员的函数都应该声明为const类型。
不能把常量指针 赋值给非常量指针， 反过来可以。

### 自动类型转换
表达式中存在有符号类型和无符号类型时所有的操作数都自动转换为无符号类型   
unsigned int a = 3;   
int b = -10;   
a + b > 0  
原因是b 转换为 uint  

自动转换遵循以下规则：

1) 若参与运算量的类型不同，则先转换成同一类型，然后进行运算。

2) 转换按数据长度增加的方向进行，以保证精度不降低。如int型和long型运算时，先把int量转成long型后再进行运算。

     a.若两种类型的字节数不同，转换成字节数高的类型

     b.若两种类型的字节数相同，且一种有符号，一种无符号，则转换成无符号类型

3) 所有的浮点运算都是以双精度进行的，即使仅含float单精度量运算的表达式，也要先转换成double型，再作运算。

4) char型和short型参与运算时，必须先转换成int型。

5) 在赋值运算中，赋值号两边量的数据类型不同时，赋值号右边量的类型将转换为左边量的类型。如果右边量的数据类型长度左边长时，将丢失一部分数据，这样会降低精度，丢失的部分按四舍五入向前舍入。

面试题链接：
http://blog.jobbole.com/109117/
https://blog.csdn.net/sailor_8318/article/details/2215041

### 整型溢出
    short a = -32766, b = -32516;
    short sum = a + b; // sum = 254 直接加
    
### 数据类型的长度

编译器可以根据自身硬件来选择合适的大小，但是需要满足约束：short和int型至少为16位，long型至少为32位，并且short型长度不能超过int型，而int型不能超过long型。这即是说各个类型的变量长度是由编译器来决定的，而当前主流的编译器中一般是32位机器和64位机器中int型都是4个字节（例如，GCC）。下面列举在GCC编译器下32位机器和64位机器各个类型变量所占字节数：

   | C类型	          | 32bit 	| 64bit |
   | -------------- |:--------:| -----:|
   | char	        |   1	    |  1    |
   | short          |   2	    |  2    |
   | uint     	     |   4	    |  4    |
   | int	           |   4	    |  4    |
   | long    	     |   4	    |  8    |
   | long long      |   8	    |  8    |
   | char*	        |   4	    |  8    |
   | float	        |   4	    |  4    |
   | double	        |   8	    |  8    |
   | size_t         |   4      |  8    |
   
需要说明一下的是指针类型存储的是所指向变量的地址，所以32位机器只需要32bit，而64位机器需要64bit。

为什么使用 size_t？
1. 保证可移植性. 32bit int - 4bytes, 64bit int - 4 bytes. size_t is aligned to address width.
2. if use uint long, 16 bit machine time complexicity is high.

### data alignment
```cpp
struct __attribute__((packed)) {
    char a, b, *c;
    int *d, e;
    short *f, g;
} test;
sizeof(test) : 20 bytes
w/o attribute packeted: sizeof(test) - 24 bytes

```

### 宏转义字符 

#define A(x) T_##x   /* 符号 */  
#define B(x) #@x   
#define C(x) #x  /* 字符串 */  

我们假设：x=1，则有：  

A(1)------〉T_1   
B(1)------〉'1'   
C(1)------〉"1"  
···
#include <stdio.h>

#define str(x)  #x
#define con(a, b) a##b


void main(void) {
    int hello_world = 1;
    printf("%s\n", str(hello));
    printf("%d\n", con(hello_, world));
}

···
### prototype
```
in file 1:
uint64_t fun(void) {
     uint64_t val = 0x1234567887654321;
     return val;
}

in file 2;
/* 
 * We need to declare fun() properly with a prototype
 * If not, compiler will use the implicit return type of int that explains truncation (you have 32-bit ints).
 */
uint64_t val = fun();
printf("%x%x\n", (val >> 32) & 0xFFFFFFFF, val & 0xFFFFFFFF);

```
