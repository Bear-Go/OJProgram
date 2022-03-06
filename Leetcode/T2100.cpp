#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> res;
        int n = security.size();
        int up[n], down[n];
        up[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (security[i - 1] >= security[i]) {
                up[i] = up[i - 1] + 1;
            } else {
                up[i] = 0;
            }
        }
        down[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (security[i] <= security[i + 1]) {
                down[i] = down[i + 1] + 1;
            } else {
                down[i] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (up[i] >= time && down[i] >= time) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main() {

    Solution s;
    vector<int> security = {1,1,1,1,1,1,1,1,1,1};
    vector<int> res = s.goodDaysToRobBank(security, 5);
    for (int i : res) {
        cout << i << " ";
    }

    return 0;
}