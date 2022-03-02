#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     void add_one(string& up) {
//         int i = up.size() - 1;
//         while (i >= 0 && up[i] == '9') {
//             up[i] = '0';
//             --i;
//         }
//         if (i >= 0) up[i] += 1;
//         else up = "1" + up;
//     }
//     void sub_one(string& down) {
//         if (down == "1" || down == "0") {
//             down = "0";
//             return;
//         }
//         int i = down.size() - 1;
//         while (i >= 0 && down[i] == '0') {
//             down[i] = '9';
//             --i;
//         }
//         if (i >= 0) down[i] -= 1;
//         if (down[0] == '0') down = down.substr(1);
//     }
//     bool is_palindrome(string s) {
//         int n = s.size();
//         for (int i = 0; i < n/2; ++i) {
//             if (s[i] != s[n-i-1]) return false;
//         }
//         return true;
//     }
//     string nearestPalindromic(string n) {
//         string up = n;
//         string down = n;
//         while (true) {
//             add_one(up);
//             sub_one(down);
//             if (is_palindrome(down)) return down;
//             if (is_palindrome(up)) return up;
//         } 
//     }
// };
// above solution is too slow

class Solution {
public:
    vector<long> getCandidates(const string& n) {
        int len = n.length();
        vector<long> candidates = {
            (long)pow(10, len - 1) - 1,
            (long)pow(10, len) + 1,
        };
        long selfPrefix = stol(n.substr(0, (len + 1) / 2));
        for (int i : {selfPrefix - 1, selfPrefix, selfPrefix + 1}) {
            string prefix = to_string(i);
            string candidate = prefix + string(prefix.rbegin() + (len & 1), prefix.rend());
            candidates.push_back(stol(candidate));
        }
        return candidates;
    }

    string nearestPalindromic(string n) {
        long selfNumber = stol(n), ans = -1;
        const vector<long>& candidates = getCandidates(n);
        for (auto& candidate : candidates) {
            if (candidate != selfNumber) {
                if (ans == -1 ||
                    abs(candidate - selfNumber) < abs(ans - selfNumber) ||
                    abs(candidate - selfNumber) == abs(ans - selfNumber) && candidate < ans) {
                    ans = candidate;
                }
            }
        }
        return to_string(ans);
    }
};
// 求回文数还是得使用构造的方法

int main() {

    Solution s;
    cout << s.nearestPalindromic("123") << endl;
    cout << s.nearestPalindromic("1") << endl;
    return 0;
}