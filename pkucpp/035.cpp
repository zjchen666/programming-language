#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
template <class T1,class T2>
struct Closer {
    T1 n;
    T2 dist;

    Closer (T1 a, T2 fn) {
       n = a;
       dist = fn;           
    }

    bool operator () (T1 a, T1 b) {
        if (dist(a, n) < dist(b, n)) {
            return true;
        } else if (dist(a, n) > dist(b, n)) {
            return false;
        } else {
            return a < b;
        }
    }
};

int Distance1(int n1,int n2) {
	return abs(n1-n2);
}
int Distance2(const string & s1, const string & s2)
{
	return abs((int)s1.length()- (int) s2.length());
}
int a[10] = { 0,3,1,4,7,9,20,8,10,15};
string b[6] = {"American","Jack","To","Peking","abcdefghijklmnop","123456789"};
int main()
{
	int n(2); string s("a123456");
	// 1. closer 是个类模板， 参数为 int 和 函数指针。
	// 2. closer 构造函数有两个参数。
	// 3. 因为是sort的入参， closer需提供（）的重载函数。
	sort(a,a+10,Closer<int, int (*)(int ,int)> (n,Distance1));
	for(int i = 0;i < 10; ++i)
		cout << a[i] << "," ;
	cout << endl;
    
	sort(b,b+6,Closer<string,int (*)(const string &,const string &  )> (s,Distance2)); 
	for(int i = 0;i < 6; ++i)
		cout << b[i] << "," ;
	cout << endl;
	
	return 0;
}
