#include <iostream>
#include <string>

using namespace std;

class Complex {
private:
    double r, i;

public:
    Complex() {r = 0; i = 0;};
 
    // 参数必须是 const 否则编译不过
    void operator=(const string& s) {
        int pos1 = s.find('+');
        int pos2 = s.find(pos1,'i');

        r = stoi(s.substr(0, pos1));
        i = stoi(s.substr(pos1 + 1, pos2));
    };
   
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
};

int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
