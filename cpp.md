## C++ 四大特性： ##
------------------------------------------------------------------------------------------
## 封装
   - 意义：使代码模块化
   - 类的定义
   - 对象的定义及初始化和释放    _TODO 对象的内存用法_? 
   - _C++接口：抽象类_
   - [引用](#引用)
       * Why? 主要用于替代指针作为函数参数的作用。避免传递类对象时拷贝构造函数的开销  
   - [构造函数](#构造函数)
       * Why? 对象的分配和释放需要构造和析构函数  
   - [拷贝构造函数](#拷贝构造函数)
       * Why? 对象的相互赋值需要copy构造函数
   - [析构函数](#析构函数)
       * Why? 对象的释放需要析够函数  
   - 重载  
       [运算符重载](#运算符重载)
       * Why? 对象的运算符操作需要C++支持运算符重载
## 继承
   - 意义：使代码扩展
   - 派生类的声明
   - 类的继承方式
   - 派生类的构造和析构函数
   - _虚基类_
## 多态
   - 意义： 使接口重用
   - 静态多态 - 函数重载
   - 动态多态 - 虚函数
   - 虚函数 - 允许被其子类重新定义的成员函数，子类重新定义父类虚函数的做法，可实现成员函数的动态覆盖（Override）。
      https://zhuanlan.zhihu.com/p/75172640
   
   - 纯虚函数 - 是在基类中声明的虚函数，它在基类中没有定义，但要求任何派生类都要定义自己的实现方法。
   - 抽象类 - 包含纯虚函数的类称为抽象类。由于抽象类包含了没有定义的纯虚函数，所以不能进行实例化。
## 范型编程
   - 模板， 类模板 和函数模板。
   - STL - 标准模板库。
-------------------------------------------------------------------------------------------

### 引用  
Why?  
因为加入引用是为了支持operator overloading。这里有一个假设，如果没有引用，那么，用指针来operator overloading操作。A operator +(const A *a, const A *_a);那么使用的时候，&a + &b，这样看起来是不是很难受。而引入引用的概念，既可以满足overload operator，也不失重载value和pointer的灵活性。而且引用还带来一个指针无法替代的特性: 引用临时对象。因为引用必须在定义的时候就赋值，以后无法更改。
主要用于替代指针作为函数参数的作用。避免传递类对象时拷贝构造函数的开销  
to avoid obj as parameter(copy constructor costs memory and time)   
TODO: __编译器如何使用引用？__

### 函数重载
多个函数，函数名相同，但是参数的个数和类型不同。

### 运算符重载
### 全局函数运算符重载
运算符重载函数既可以声明为类的成员函数，也可以声明为所有类之外的全局函数。
将运算符重载函数声明为全局函数时，二元操作符需要两个参数，一元操作符需要一个参数，而其中必须有一个参数是对象，好让编译器区分这是程序员自定义的运算符。

- 重载为普通函数时参数为运算符的目数
- 重载为成员函数时参数为运算符的目数-1
   
### 构造函数
   1. 定义一个对象时先调用基类的构造函数、然后调用派生类的构造函数；析构的时候恰好相反：先调用派生类的析构函数、然后调用基类的析构函数。
   2. 一个类可以有多个构造函数。参数个数和参数类型不同。
   3. 构造函数的写法。  
   
   a. 主要用于不带类成员变量的类初始化    
```cpp
        int a;  
        int b;  
        class_name(int x, int y, ...) {  
            a = x;  
            b = y;  
            ...  
     }   
```
        
  b. 主要用于封闭类（带类成员变量的类）    
```cpp  
         class1 obj;  
         int a;  
         class_name(int x, int y): a(x), obj(y) {}  
```  
### Lamda 表达式：
```cpp
[](参数列表) “->(返回值类型)” {  
   // 函数实现  
}
```
[=] 以传值的形式使用所有外部变量  
[] 不使用任何外部变量  
[&] 以引用形式使用所有外部变量  
[x, &y] x 以传值形式使用，y 以引用形式使用  
[=,&x,&y] x,y 以引用形式使用，其余变量以传值形式使用  
[&,x,y] x,y 以传值的形式使用，其余变量以引用形式使用  
“->返回值类型”也可以没有， 没有则编译器自动判断返回值类型。  

### 拷贝构造函数   
```cpp
    //使用const能以常量作为参数 
    classname (const classname &obj) {
    // 构造函数的主体
    }
    
    不允许 以下的copy 构造函数
    classname (classname obj) {
    // 构造函数的主体
    }
```

   用来init而不是赋值。  
   三种用法：  
   1. 函数的形参init，用实参来init  
   2. return值，用函数内要return的变量来init  
   3. 定义类变量时： A c1(c2) / A c1 = c2; c1 = c2不是。  
   
### 析构函数
   __虚析构函数__ - 如果基类指针指向派生类对象并且使用基类指针来释放派生类时， 需要定义基类的析构函数为虚函数。
   这是因为编译器不知道释放的是基类还是派生类。
   
### 对象的引用
1.对象直接引用 OBJ obj, obj.x  
2.对象指针 OBJ* pObj; pObj->x  
3.对象引用 OBJ & obj1 = obj; obj1.x  

### 函数对象  
   若一个类重载了运算符 “()”，则该类的对象就成为函数对象。  
   为什么要使用函数对象？ 当函数对象和函数指针作为函数模板入参的时候，函数对象可以带初始化参数，这样更灵活
   
### 类对象的size
非虚函数， - 不占内存.  
虚函数， - 虚函数表 pointer size。  
静态数据 - 不算对象内存  
非静态数据 - 算。  
占位符 - size 1  

### 类函数的定义
1.在定义类的时候。在类内部定义的成员函数默认是inline的   
2.在类的内部之声明函数， 在函数外以 类名：：函数名 的形式定义。  

## 继承与派生
  1. 子类的构造函数要给调用基类的构造函数
```cpp
   class Derived:public Base
   {
       public:
            Derived(int i):Base(i) {
                cout << "Derived constructed" << endl;
            }
            ~Derived() {
            cout << "Derived destructed" << endl;
            }
};
```

### 类成员变量
private(default): 只能自己调用。
public: 都可以调用。
protected: 自己和派生类调用。

## 虚函数
 1. 基类指针指向派生类的对象。
 2. 基类的引用指向派生类的对象。
 3. 基类指针指向谁就调用谁的虚函数。

## 字符串 流 _TODO__ 
 
## [C++ STL](#stl)
[Misc](#misc)  
    - [lambda](#lambda)  
    - [power](#power)  
[String](#string)   
[Stack](#stack)  
[Vector](#vector)  
[pair](#pair)  
[hashmap](#hashmap)  
[priority_queue](#priority_queue)  
[map](#map)  
[sort](#sort)

## STL
| vector         | string      | deque         | stack | queue      | priority_queue | unordered_set | unordered_map | list     |   
| ---------------|-------------|:-------------:| -----:| -----------|----------------|---------------|---------------|----------|
| push_back      | push_back   | push_back     | push  |  push      | push           | insert        | N/A           |push_back |
| pop_back       | pop_back    | pop_back      | pop   |  pop       | pop            | erase         | erase         |pop_front |
| N/A            | N/A         | push_front    | N/A   |  N/A       | N/A            |               |               |push_front|
| N/A            | N/A         | pop_front     | N/A   |  N/A       | N/A            |               |               |pop_front |
| front          | front       | front         | top   |  front     | top            |               |               |          |
| back           | back        | back          | N/A   |  back      | N/A            |               |               |          |
| size           | size        | size          | size  |  size      | size           |               |               |          |
| empty          | empty       | empty         | empty |  empty     | empty          |               |               |          |
| find -> end()  | find -> npos|               |       |            |                |               |               |          |
| random iterator| random      | random        | N/A   | N/A        | N/A            | bi-direction  | bi-direction  |    







| 容器	   | 底层数据结构	| 元素访问方式	| 插入或删除元素效率	| 迭代器失效情况 |
|---------|------------|------------|-----------------|--------------|
|array	 | 固定大小的数组	| 支持快速随机访问	|不能添加或删除元素	| 通常不会发生迭代器失效，除非对象已经被销毁，则原来的迭代器全部失效
|vector |	可动态增长的数组	| 支持快速随机访问	| 尾部可高效插入/删除元素	| 若插入操作引起内存重新分配，则全部迭代器失效；否则插入点/删除点之后的迭代器失效;
|list	 | 双向链表	| 只支持元素的双向顺序访问	|在list的任何位置可高效插入/删除元素	|插入操作后指向容器的迭代器有效；删除操作指向其他位置的迭代器有效
|deque	|list + vector	支持index，首尾快速增删	|首尾可高效插入/删除元素|	情况较多，见上面分析
|string	|只存储字符元素的动态数组	|支持快速随机访问|	尾部可高效插入/删除元素|	若插入操作引起内存重新分配，则全部迭代器失效；否则插入点/删除点之后的迭代器失效;
|stack	|是deque的包装 |先进后出|只能访问栈顶元素 |	----	|没有迭代器|
|queue	|是deque的包装 |先进先出|只能访问队首元素	|----	 |没有迭代器|
|priority-queue	|默认max-heap|	先进先出，只能访问队首元素|	----	|没有迭代器 |

### misc
#### lambda
```cpp
[外部变量访问方式说明符](参数表) ->返回值类型
[=] 以传值的形式使用所有外部变量
[] 不使用任何外部变量
[&] 以引用形式使用所有外部变量
[x, &y] x 以传值形式使用，y 以引用形式使用
[=,&x,&y] x,y 以引用形式使用，其余变量以传值形式使用
[&,x,y] x,y 以传值的形式使用，其余变量以引用形式使用


[](int x, int y) {
   return x + y;
};
```

```cpp
   1e9  10**9
```
#### Initialization
```cpp
    /* hashmap */
    unordfered_map<int, int> map = {{1, 2}, {3, 4}, {5, 6}};
    
    /* pair */
    vector<pair<int, int>> pair = {{1, 2}, {1, 2}}
    
    /*2D vector*/
    int m = 2, n = 5;
    vector<vector<int>> vec(m, vector<int> (n, 2));
```
#### swap：  
swap（x, y）

#### iterator
iterator is a pointer.
```cpp
        for (string::reverse_iterator it = s.rbegin(); it < s.rend(); it++)
        {
            res.push_back(*it);
        }
        reverse() 区间 [first,last)
        
        for (auto it = map.begin(); it != map.end(); it++){
            it->first; // key
            it->second; // values
        }
 ```
### auto:
### vector:
vector的几种初始化及赋值方式：
（1）不带参数的构造函数初始化
```cpp
//初始化一个size为0的vector
vector<int> abc;
```

2）带参数的构造函数初始化
```cpp
//初始化size,但每个元素值为默认值
vector<int> abc(10);    //初始化了10个默认值为0的元素
//初始化size,并且设置初始值
vector<int> cde(10，1);    //初始化了10个值为1的元素
```

（3）通过数组地址初始化
```cpp
int a[5] = {1,2,3,4,5};
//通过数组a的地址初始化，注意地址是从0到5（左闭右开区间）
vector<int> b(a, a+5);
```

（4）通过同类型的vector初始化
```cpp
vector<int> a(5,1);
//通过a初始化
vector<int> b(a);
```

```cpp
   vector<int> nums
   iterator nums.begin(), nums.end()
   vector<int> map(26,0) -- Init a vector size 26 value 0
   //2D vector initialization
   vector<vector<int>> f(3, vector<int>(3, 0x3));
   vector<string>

   vector<double>

   size()

   push_back()
   back()
   pop_back() - doesn't return any value
```
### pair:
```cpp
    make_pair((x, y))
    a.first, a.second
```
### list:
### stack:
```cpp
   stack int s;
   s.push(1)
   s.pop() - Doesn't return any value. top first then pop.
   s.top()
```
### deque:

### sort()   
sort(a.begin(), a.end());  
sort(a.rbegin(), a.rend());  
sort(data.begin(), data.end(), greater< int >());
   
### comparator
__必须严格弱序！！！ x < y / x > y__
```cpp
struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val; // reversed
        return l->val < r->val; // not reversed
    }
};
```
```cpp
// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main () {
  int myints[] = {32,71,12,45,26,80,53,33};
  std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

  // using default comparison (operator <):
  std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

  // using function as comp
  std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

  // using object as comp
  std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)
  
  // using class as comp
  std::sort (myvector.begin(), myvector.end(), myclass());     //(12 26 32 33 45 53 71 80)
  
  // using lambda 
  std::sort (myvector.begin(), myvector.end(), [](int a, int b){return a < b;});     //(12 26 32 33 45 53 71 80)
  
  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
```
### priority_queue:
#### define
```cpp
   Max Heap: priority_queue<int> max_heap; __DEFAULT__  
   Min Heap: priority_queue<int, vector <int>, greater<int>> min_heap;    
   Heap with self defined comparator: priority_queue<int, vector <int>, cmp> heap; //cmp 是第三个参数
```
### hashmap:
```cpp
   unordered_map<char, int> map;
   if (map.find(key) != map.end())
```
hash_set:
```cpp
   // 直接用vector初始化
   unordered_set<string> map(wordDict.begin(), wordDict.end());
   unordered_set<char> set;
   if (set.find(key) != set.end())
   set.insert(val)
   set.delete(val)
```
### string:
```cpp
   string s, s.push_back(), s.size(), s.pop()
   isalnum(c), isdigit(c), isalpha(c), tolower(c)
   // find
   pos = s.find(a, index) != string::npos;
   //string::npos == 0xFFFFFFFF
   str.substr(start_pos, len) - python str[start:end]
   // add
   s + "sdsdsa" // is supported by CPP， 字符串操作
   s.push_back() // char 类型操作
   // replace
   s.replace(pos, len, str);
   
   // digital char to int convert
   int -> char: c + '0'
   char-> int: c - '0'
   
   // string compare
   string1 > string2
```
### map:
    有序的 hashmap
    map<key, val> map;
    
    lower_bound(val) (first key >= val)
    upper_bound(val) (first key > val)
    
```cpp
    map<int, int> m;
    unordered_map<int, int> a;

    a[1] = 1;
    m[5] = 50;
    m[7] = 70;

    cout << m.lower_bound(6)->second << endl; // 70
    cout << m.upper_bound(6)->second << endl; // 70
    cout << m.lower_bound(5)->second << endl; // 50
    cout << m.upper_bound(5)->second << endl; // 70
    cout << m[6] << endl; // 0
    cout << a[5] << endl; // 0
```
### queue:
```cpp
    queue <int> q
    q.pop()
    q.push()
    q.back()
    q.front()
```
   
定义queue对象的示例代码如下：

queue<int> q1;

queue<double> q2;

queue的基本操作有：

入队，如例：q.push(x); 将x接到队列的末端。

出队，如例：q.pop(); 弹出队列的第一个元素，注意，并不会返回被弹出元素的值。

访问队首元素，如例：q.front()，即最早被压入队列的元素。

访问队尾元素，如例：q.back()，即最后被压入队列的元素。

判断队列空，如例：q.empty()，当队列空时，返回true。

访问队列中的元素个数，如例：q.size()

### class
### public, protected, private
 1. 成员变量：   
    public - 可以被任意调用  
    protected - 子类和内部函数调用  
    private - 只能内部函数调用  
 2. 继承方式：   
    public - public->public, protected->protected, private->private.  
    protected - public->protected, protected->protected, private->private.  
    private - public->private, protected->private, private->private. 
    
### new、delete、malloc、free
   new - 调用类的构造函数
   delete - 调用类的析构函数
   malloc - 分配内存
   free  - 释放内存
   
### delete与 delete []区别
    delete - 析构一个元素
    delete[] - 析构一个元素数组。
```cpp
MemTest *mTest1=new MemTest[10];

MemTest *mTest2=new MemTest;

Int *pInt1=new int [10];

Int *pInt2=new int;vector

delete[]pInt1; 

delete[]pInt2; 

delete[]mTest1;

delete[]mTest2;// - 出错

```

### 格式化输出：
```cpp
Int ("%d"): 32 Bit integer
Long ("%ld"): 64 bit integer
Char ("%c"): Character type
Float ("%f"): 32 bit real value
Double ("%lf"): 64 bit real value
```
