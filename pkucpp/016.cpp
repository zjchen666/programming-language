#include <iostream> 
using namespace std;
class Point { 
	private: 
		int x; 
		int y; 
	public: 
		Point() { };
        
    // 在此处补充你的代码
    friend istream & operator >> (istream & in, Point & obj) {
		 in >> obj.x >> obj.y;
		 return in;
	}

    friend ostream & operator << (ostream & o, Point & obj) {
	   o << obj.x << ',' << obj.y;
	   return o;		
    }
};

int main() 
{ 
 	Point p;
    /* notes:
      1. 需要重载 >> 和 <<
      2. 重载 >> 和 << 需要全局函数， 参数1：运算符左边， 参数2： 运算符右边。而不能是成员函数。
      3. x, y 为私有变量，需要使用友元函数。
    */
 	while(cin >> p) {
 		cout << p << endl;
	}
	return 0;
}