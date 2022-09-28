#include <bits/stdc++.h>

using namespace std;

void getNumber(string num, int &a, int &b) {
    a = 0; b = 0; int i = 0;
    bool aflag = false, bflag = false;
    if (num[i] == '-') {
        i++;
        aflag = true;
    }
    while (num[i] != '+') {
        a = a * 10 + num[i] - '0';
        i++;
    }
    i++;
    if (num[i] == '-') {
        i++;
        bflag = true;
    }
    while (num[i] != 'i') {
        b = b * 10 + num[i] - '0';
        i++;
    }
    if (aflag) a = -a;
    if (bflag) b = -b;
}

string getString(int a, int b) {
    string ret, t;
    if (a == 0) 
        t += '0';
    else {
        if (a < 0) ret += '-';
        a = abs(a);
        while (a > 0) {
            char c = '0' + (a % 10);
            t = c + t;
            a /= 10;
        }
    }
    ret += t + '+';
    t = "";
    if (b == 0)
        t += '0';
    else {
        if (b < 0) ret += '-';
        b = abs(b);
        while (b > 0) {
            char c = '0' + (b % 10);
            t = c + t;
            b /= 10;
        }
    }
    ret += t + 'i';
    return ret;
}

int main() {
    string num1, num2;
    cin >> num1 >> num2;

    int a1, b1, a2, b2;
    getNumber(num1, a1, b1);
    getNumber(num2, a2, b2);

    cout << getString(a1*a2-b1*b2, a1*b2+a2*b1) << endl;
    return 0;
}

/*
    sscanf() sprintf() 可以直接秒
*/