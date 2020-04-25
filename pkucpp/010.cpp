#include <iostream>
using namespace std;
class A {
public:
	int val;

	  A(int i) {val = i;}
    A() {val = 123;}
    
    // 返回 obj 自己
    A & GetObj() {return *this;};
    
    // = 的运算符重载
    void operator = (const int m) 
    {
        val = m;
    }

    void operator = (const A & obj) {
        val = obj.val;
    }
};


int main()
{
	int m,n;
	A a;
	cout << a.val << endl;
	while(cin >> m >> n) {
		a.GetObj() = m;
		cout << a.val << endl;
		a.GetObj() = A(n);
		cout << a.val<< endl;
	}
	return 0;
}
