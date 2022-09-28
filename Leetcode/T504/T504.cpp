#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string res;
        bool neg = num < 0;
        if (neg) num = -num;
        while (num) {
            res.push_back(num % 7 + '0');
            num /= 7;
        }
        if (neg) res.push_back('-');
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {

    Solution s;
    cout << s.convertToBase7(100) << endl;
    cout << s.convertToBase7(-7) << endl;

    return 0;
}