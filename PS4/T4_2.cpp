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
    int n;
    cin >> n;
    vector<vector<int>> points(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }
    
    Solution s;
    
    cout << s.maxPoints(points) << endl;

    return 0;
}