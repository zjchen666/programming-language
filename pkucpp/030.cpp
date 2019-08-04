#include <iostream>
using namespace std;
class MyCin
{
    // 在此处补充你的代码
public:
    int data;
    MyCin() : data(0) {}  
    MyCin & operator >> (int & a) {
        if (data != -1){
            cin >> data;
            a = data;
        } 
        return *this;
    }

    operator bool () {
        if (data == -1) {
            return false;
        } else {
            return true;
        }
    }
};
int main()
{
    MyCin m;
    int n1,n2;
    while( m >> n1 >> n2) 
        cout  << n1 << " " << n2 << endl;
    return 0;
}