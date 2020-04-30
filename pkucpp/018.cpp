#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110;


class CHugeInt {
public:
    string num;
void _reverse(string& s) {
    int i = 0, j = s.size() - 1;

    while (i < j) {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return;
}

string addString(string& s1, string& s2) {
    int i = s1.size() - 1, j = s2.size() - 1;
    int carry = 0, tmp = 0;
    string res;

    while (i >= 0 || j >= 0 || carry) {
        tmp = carry;
        if (i >= 0) {
            tmp += s1[i] - '0';
            i--;
        }

        if (j >= 0) {
            tmp += s2[j] - '0';
            j--;
        }

        carry = tmp / 10;
        res.push_back(tmp % 10 + '0');
    }

    _reverse(res);

    return res;
}


    CHugeInt(const char* s) {
        while (*s != '\0') {
            num.push_back(*s);
            s++;
        }
    }

    CHugeInt(int a) {
        num = to_string(a);
    }

    CHugeInt(string & s): num(s) {}

    string operator + (CHugeInt & obj) {
        return addString(num, obj.num);
    }

    string operator + (int n) {
        string tmp = to_string(n);
        return addString(num, tmp);
    }

    void operator += (int n) {
        string tmp = to_string(n);
        num = addString(num, tmp);
    }

    // 自增 left
    CHugeInt & operator++ () {
        string tmp = "1";
        num = addString(num, tmp);
        return *this;
    }

    // 自增 right
    CHugeInt & operator++ (int) {
        CHugeInt *tmp = new CHugeInt(num);

        string s = "1";
        num = addString(num, s);

        return *tmp;
    }

    friend ostream& operator << (ostream & out, CHugeInt & obj);
    friend string operator + (int n, CHugeInt & obj);

};

ostream & operator << (ostream & out, CHugeInt & obj) {
    out << obj.num;
    return out;
}

string operator + (int n, CHugeInt & obj) {
    string tmp = to_string(n);
    return obj.addString(tmp, obj.num);
};

int  main() 
{ 
	char s[210];
	int n;

	while (cin >> s >> n) {
		CHugeInt a(s);
		CHugeInt b(n);

		cout << a + b << endl;
		cout << n + a << endl;
		cout << a + n << endl;
		b += n;
		cout  << ++ b << endl;
        cout << b++ << endl;
		cout << b << endl;
	}
	return 0;
}
