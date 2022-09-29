// 面试题 01.05. 一次编辑

// 字符串有三种编辑操作:插入一个英文字符、删除一个英文字符或者替换一个英文
// 字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。



#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (first.length() == second.length()) {
            int diff_cnt = 0;
            for (int i = 0; i < first.length(); ++i) {
                if (first[i] != second[i]) diff_cnt++;
            }
            return (diff_cnt <= 1);
        }
        if (first.length() > second.length()) {
            string t = second;
            second = first;
            first = t;
        }
        if (second.length() - first.length() == 1) {
            int a = 0, b = 0;
            int diff_cnt = 0;
            while (a < first.length() && b < second.length()) {
                if (first[a] == second[b]) {
                    a++;
                    b++;
                }
                else b++;
                if (b - a > 1) return false;
            }
            return true;
        }
        return false;
    }
};

int main() {
    Solution p;
    cout << p.oneEditAway("pele", "paler") << endl;
    cout << p.oneEditAway("pale", "ple") << endl;
    cout << p.oneEditAway("pales", "pal") << endl;
}