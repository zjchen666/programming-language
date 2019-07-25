#include <iostream>
#include <string>
#include <cstring>
using namespace std;
template <class T>  
class myclass {
// 在此处补充你的代码
    T* p; 
    int size;
public:
    myclass(T* array, int n) {
        p = new T [n];
        size = n;
        for (int i = 0; i < n; ++i) {
            p[i] = *(array + i);
        }
    }

    ~myclass( ) {
		delete [] p;
	}

	void Show()
	{
		for( int i = 0;i < size;i ++ ) {
			cout << p[i] << ",";
		}
		cout << endl;
	}
};
int a[100] = {1,2,3,4};
int main() {
	char line[100] = "Tom";
	myclass<char> obj(line,strlen(line));
	obj.Show();
	myclass<int> obj2(a,4);
	obj2.Show();
	return 0;
}