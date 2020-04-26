#include <iostream>
using namespace std;

struct A
{
	int v;
	A(int vv):v(vv) { }
    // const 成员函数
    //1.c++的一个机制，让该函数的权限为只读，也就是说它没法去改变成员变量的值。
    //2.同时，如果一个对象为const，它只有权利调用const函数，因为成员变量不能改变。

    const A* getPointer() const {
        return this;
    }
};

int main()
{
	const A a(10);
	const A * p = a.getPointer();
	cout << p->v << endl;
	return 0;
}
