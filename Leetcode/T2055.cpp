#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> res;     
        int n = s.size();             
        vector<int> sum(n + 1, 0);
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        for (int i = 0, p = -1; i < n; i++) {
            sum[i+1] = sum[i];
            if (s[i] == '|') {
                p = i;
            } else {
                sum[i+1]++;
            }
            left[i] = p;
        }
        for (int i = n - 1, p = n; i >= 0; i--) {
            if (s[i] == '|') {
                p = i;
            } 
            right[i] = p;
        }
        for (auto& q : queries) {
            int l = right[q[0]];
            int r = left[q[1]];
            if (l < r) 
                res.push_back(sum[r] - sum[l]);
            else
                res.push_back(0);
        }
        return res;
    }    
};

int main() {

    Solution s;
    vector<vector<int>> queries = {{2,5},{5,9}};
    vector<int> res = s.platesBetweenCandles("**|**|***|", queries);
    for (auto& r : res) {
        cout << r << " ";
    }
    cout << endl;
    return 0;
}