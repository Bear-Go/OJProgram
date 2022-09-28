#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> grid;
int main() {

    int m, n, t;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        vector<int> line;
        for (int j = 0; j < n; ++j) {
            cin >> t;
            line.push_back(t);
        }
        grid.push_back(line);
    }

    m = grid.size();
    n = grid[0].size();
    
    vector<int> ans[2];
    for (int i = 0; i < n; ++i) {
        ans[0].push_back(i);
        ans[1].push_back(0);
    }

    for (int i = 0; i < m; ++i) {

        int nxt = (i + 1) % 2;
        for (int j = 0; j < n; ++j) {
            int pos = ans[i%2][j];
            if (pos == -1) {
                ans[nxt][j] = -1;
                continue;
            }

            if (grid[i][pos] == 1) {
                if ((pos < n-1 && grid[i][pos+1] == -1) || pos == n-1) {
                    ans[nxt][j] = -1;
                }
                else {
                    ans[nxt][j] = pos + 1;
                }
            }
            else {
                if ((pos > 0 && grid[i][pos-1] == 1) || pos == 0) {
                    ans[nxt][j] = -1;
                }
                else {
                    ans[nxt][j] = pos - 1;
                }
            }
        }
        for (int j = 0; j < n; ++j) {
            cout << ans[nxt][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
    经典判边界，条件判断中需要先判定下表是否合法，再继续
    e.g.
    if ((pos > 0 && grid[i][pos-1] == 1) || pos == 0)
*/