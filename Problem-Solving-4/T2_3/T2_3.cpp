#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;
bool G[maxn][maxn];
int P[maxn][maxn], X[maxn][maxn], R[maxn][maxn];
int n, m, ans = 0;

void dfs(int d, int Rn, int Pn, int Xn) {
    if (!Pn && !Xn) ++ans;
    int u = P[d][0];
    for (int i = 0; i < Pn; ++i) {
        int v = P[d][i];
        if (G[u][v]) continue; 
        for (int j = 0; j < Rn; ++j) {
            R[d+1][j] = R[d][j];  
        }
        R[d+1][Rn] = v;
        int tPn = 0, tXn = 0;
        for (int j = 0; j < Pn; ++j)  if (G[v][P[d][j]])  P[d+1][tPn++] = P[d][j];
        for (int j = 0; j < Xn; ++j)  if (G[v][X[d][j]])  X[d+1][tXn++] = X[d][j];
        dfs(d+1, Rn+1, tPn, tXn);
        P[d][i] = 0, X[d][Xn++] = v;
    }
}

int main() {
    cin >> n >> m;
    memset(G, 0, sizeof(G));
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }
    for (int i = 0; i < n; ++i) P[1][i] = i + 1;
    dfs(1, 0, n, 0);
    cout << ans << endl;
    return 0;
}