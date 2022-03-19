#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int res = 0;
        for (int i = 0; i < n; ++i) {
            unordered_map<double, int> m;
            int dup = 0, max_cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    ++dup;
                    continue;
                }
                double k = (points[i][1] - points[j][1]) * 1.0 / (points[i][0] - points[j][0]);
                m[k]++;
                max_cnt = max(max_cnt, m[k]);
            }
            res = max(res, max_cnt + dup + 1);
        }
        return res;
    }
};

int main() {
    Solution s;
    // vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout << s.maxPoints(points) << endl;
    return 0;
}