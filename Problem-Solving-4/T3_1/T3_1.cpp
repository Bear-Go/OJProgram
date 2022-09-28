#include <bits/stdc++.h>

using namespace std;

const int maxn = 1505;

int n;
int dp[maxn][2];
vector<int> g[maxn];
void dfs(int u) {
    dp[u][1] = 1;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        dfs(v);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0], dp[v][1]);
    }
}

int main() {
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
        int index, k;
        cin >> index >> k;
        g[index].clear();
        for (int j = 0; j < k; ++j) {
            int v;
            cin >> v;
            g[index].push_back(v);
        }
    }
    dfs(0);
    cout << min(dp[0][0], dp[0][1]) << endl;
    return 0;
}