#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ret;
        for (int j = 0; j < s.size(); j += 2 * numRows - 2) {
            ret += s[j];
        }
        for (int i = 1; i < numRows - 1; i++) {
            int len = numRows - i - 1;
            for (int j = numRows - 1; j < s.size() + 2 * numRows - 2; j += 2 * numRows - 2) {
                if (j - len < s.size())
                    ret += s[j - len];
                if (j + len < s.size())
                    ret += s[j + len];
            }
        }
        for (int j = numRows - 1; j < s.size(); j += 2 * numRows - 2) {
            ret += s[j];
        }
        return ret;
    }
};

int main() {

    Solution s;
    cout << s.convert("PAYPALISHIRING", 4) << endl;
    return 0;
}