#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        if (num < 10) return num;
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return addDigits(sum);
    }
};

int main() {

    Solution s;
    cout << s.addDigits(38) << endl;

    return 0;
}