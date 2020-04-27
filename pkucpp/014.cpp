#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;

	}

	~MyString() { if(p) delete [] p; }

  // 1. copy constructor function
	MyString(MyString & obj) {
		if(obj.p) {
			p = new char[strlen(obj.p) + 1];
			strcpy(p,obj.p);
		}
		else
			p = NULL;
	}

    // 2. overwrite operator =
    void operator = (const MyString & obj) {
        if (p) delete [] p;

	    if(obj.p) {
			p = new char[strlen(obj.p) + 1];
			strcpy(p,obj.p);
		}
		else
			p = NULL;
    }

    // 3. implement copy()
    void Copy(const char* s) {
        if (p) delete [] p;

	    if(s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;
    }

    // 4. 重载流插入运算符 <<
    // a 为什么要写成全局重载？ -> 因为重载的是ostream 类并不是 MyString 类。
    // b 为什么返回值为ostream对象？-> 因为要支持 cout << a << b;
    friend ostream & operator << (ostream & out, MyString & obj);

};

ostream & operator << (ostream & out, MyString & obj) {
    out << obj.p;
    return out;
}

int main()
{
	char w1[200],w2[100];
	while( cin >> w1 >> w2) {
		MyString s1(w1),s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;
		
	}
}
