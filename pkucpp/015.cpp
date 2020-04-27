#include <iostream> 
using namespace std;
class MyInt 
{ 
	int nVal; 
	public:

  int flag;
	MyInt( int n) { nVal = n ;}

    // 1. 重载- 运算符
    MyInt & operator - (int n) {
        nVal -= n;
        if(n == 3) flag = 1;
        else flag = 0;

        return *this;
    }

    // 2. 重载 Inc 函数
    friend int Inc(MyInt &obj) {
        return obj.flag ? ++obj.nVal: obj.nVal;
    }
}; 
int Inc(int n) {
	return n + 1;
}
int main () { 
	int n;
	while(cin >>n) {
		MyInt objInt(n); 
		objInt-2-1-3; 
		cout << Inc(objInt);
		cout <<","; 
		objInt-2-1; 
		cout << Inc(objInt) << endl;
	}
	return 0;
}
