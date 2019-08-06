#include <iostream>
using namespace std;
class A {
public:
	int val;
	A(int a) : val(a) {}
    A() { val = 123;}
    A & GetObj() {return *this;}
    void operator = (int a) {
        val = a;
    }
    // 注意这里要用常引用， 因为A(n)是一个临时对象，不能改变它的变量。
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