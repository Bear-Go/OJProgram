// 面试题 17.09. 第 k 个数

// x = 3 ^ a * 5 ^ b * 7 ^ c (a,b,c >= 0)

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getKthMagicNumber(int k) {
        int vec[k];
        vec[0] = 1;
        int a, b, c;
        a = b = c = 0;
        for (int i = 1; i < k; ++i) {
            vec[i] = min(vec[a]*3, min(vec[b]*5, vec[c]*7));
            a += vec[i] == vec[a]*3;
            b += vec[i] == vec[b]*5;
            c += vec[i] == vec[c]*7;
        }
        return vec[k-1];
    }
};

int main() {
    Solution p;
    cout << p.getKthMagicNumber(15) << endl;
}