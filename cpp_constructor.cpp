#include <iostream>
using namespace std;
class Sample {
public:
	int v;
    // 在此处补充你的代码
    Sample() {
        cout << "constructor 1" << endl;
    }
    Sample(int a)
    {
        cout << "constructor 2" << endl;
        v = a;
    }
    Sample( const Sample & S) {
        v = S.v + 2;
        cout << "copy constructor" << v << endl;
    }
};
void PrintAndDouble(Sample o) // 如果参数为引用，则减少一次拷贝构造函数的调用
{
	cout << o.v;
	cout << endl;
}
int main()
{
	Sample a(5); // constructor
	Sample b = a; // copy constructor
	PrintAndDouble(b); // copy constructor
	Sample c = 20; // constructor
	PrintAndDouble(c);
	Sample d; //constructor
	d = a; //operator =
	cout << d.v << endl;

	return 0;
}
