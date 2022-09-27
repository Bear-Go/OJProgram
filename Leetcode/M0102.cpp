// 面试题 01.02. 判定是否互为字符重排

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) return false;
        }
        return true;
    }
};

void test1() {
    
}

void test2() {

}

int main() {
    test1();
    test2();
}
