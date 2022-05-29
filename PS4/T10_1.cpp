#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;

int n, q, w[MAXN + 50], xsum[MAXN + 50];
int anc[MAXN + 50][21], depth[MAXN + 50];
vector<int> v[MAXN + 50];

void dfs(int cur, int father) {
    anc[cur][0] = father;
    depth[cur] = depth[father] + 1;
    xsum[cur] = (xsum[father] ^ w[cur]);
    for (int i = 1; i <= 20; i++)
        anc[cur][i] = anc[anc[cur][i - 1]][i - 1];
    for (auto y : v[cur]) if (y != father) dfs(y,cur);
}

int query_lca(int u, int v) {
    if (depth[u]<depth[v]) swap(u,v);
    for (int i = 20; i >= 0; i--)
        if (depth[anc[u][i]] >= depth[v]) u = anc[u][i];
    if (u == v) return v;
    for (int i = 20; i >= 0; i--)
        if (anc[u][i] != anc[v][i]) {
            u = anc[u][i];
            v = anc[v][i];
        }
    return anc[u][0];
}

int main() {
    cin >> n >> q;
    int x, y;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n - 1; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0);
    while (q--) {
        cin >> x >> y;
        cout << (xsum[x] ^ xsum[y] ^ w[query_lca(x, y)]) << endl;
    }
    return 0;
}