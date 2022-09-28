#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        int north[n];
        for (int i = 0; i < n; ++i) {
            int maxHeight = 0;
            for (int j = 0; j < n; ++j) {
                maxHeight = max(maxHeight, grid[j][i]);
            }
            north[i] = maxHeight;
        }
        int west[n];
        for (int i = 0; i < n; ++i) {
            int maxHeight = 0;
            for (int j = 0; j < n; ++j) {
                maxHeight = max(maxHeight, grid[i][j]);
            }
            west[i] = maxHeight;
        }
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                sum += min(west[i], north[j]) - grid[i][j];
            }
        }
        return sum;   
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
    cout << s.maxIncreaseKeepingSkyline(grid) << endl;
    return 0;
}