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
void PrintAndDouble(Sample o)
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
	Sample d;
	d = a;
	cout << d.v << endl;

	return 0;
}
