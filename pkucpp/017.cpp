#include <iostream>
#include <cstring>
using namespace std;
/* Notes:
 * 1. 2D array create.
 * 2. 需要重载()及[]运算符
 * 3. 注意[]运算符重载函数的返回值为 int ×
 * 4. 需要重载=运算符， 而不是copy 构造函数。
 */

class Array2 {
    public:
    int **p;
    int a;
    int b;
    Array2(int x, int y) {
        p = new int* [x];
        for (int i = 0; i < x; ++i) {
            p[i] = new int [y];
        }
        a = x;
        b = y;
    }

    Array2(): p(NULL), a(0), b(0) {
        p = NULL;
    }

    ~Array2() {
        for (int i = 0; i < a; ++i) {
            delete p[i];
        }
        delete p;
    }

    void operator=(Array2 & arr) {
        if (p == NULL) {
            a = arr.a;
            b = arr.b;
            p = new int* [a];
            for (int i = 0; i < a; ++i) {
                p[i] = new int [b];
            }
        }   
            

        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                p[i][j] = arr.p[i][j];
            }
        } 
    }

    int* operator [] (int i) {
        return p[i];
    }

    int operator () (int x, int y) {
        return p[x][y];
    }

};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
