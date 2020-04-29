#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
private:
    uint32_t grade[4];
    string   name;
    float    avg;

public:
    Student() {
        grade[0] = 0;
        grade[1] = 0;
        grade[2] = 0;
        grade[3] = 0;
        avg = 0;
    }

    void input() {
        string s;
        int pos = -1;

        getline(cin, s);

        for (int i = 0; i < 3; ++i) {
            pos = s.find(',', pos + 1);
        }

        name = s.substr(0, pos + 1);
        s = s.substr(pos + 1);

        for (int i = 0; i < 3; ++i) {
            pos = s.find(',');
            string tmp = s.substr(0, pos);
            s = s.substr(pos + 1);
            grade[i] = stoi(tmp);
        }

        grade[3] = stoi(s);
    }

    void calculate() {
        avg = ((float)grade[0] + (float)grade[1] + (float)grade[2] + (float)grade[3]) / 4;
    }

    void output() {
        cout << name << avg << endl;
    }
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}
