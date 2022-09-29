#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string replaceSpaces(string S, int length) {
        string res = "";
        for (int i = 0; i < length; ++i) {
            if (S[i] == ' ') res += "%20";
            else res += S[i];
        }
        return res;
    }
};

int main() {
    Solution p;
    cout << p.replaceSpaces("Mr John Smith    ", 13) << endl;
    cout << p.replaceSpaces("               ", 5) << endl;
}