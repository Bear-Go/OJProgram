#include <bits/stdc++.h>

using namespace std;

#define N 20000
#define MAX 40005

vector<int> g[MAX], g2[MAX];
bool vis[MAX];
int s[MAX], color[MAX];
int n, cnt, sccCnt, k, m;

void dfs1(int u) {
    vis[u] = true;
    for (int v : g[u])
        if (!vis[v]) dfs1(v);
    s[++cnt] = u;
}

void dfs2(int u) {
    vis[u] = true;
    color[u] = sccCnt;
    for (int v : g2[u])
        if (!vis[v]) dfs2(v);
}

void kosaraju() {
    memset(vis, 0, sizeof(vis));
    memset(color, 0, sizeof(color));
    memset(s, 0, sizeof(s));
    cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) dfs1(i);
    memset(vis, 0, sizeof(vis));
    sccCnt = 0;
    for (int i = n; i >= 1; --i)
        if (!vis[s[i]]) {
            ++sccCnt;
            dfs2(s[i]);
        }
}

void add_edge(int fr, int to) {
    g[fr].push_back(to);
    g2[to].push_back(fr);
}

void add(int a, int b) {
    int fa = (a > 0), fb = (b > 0);
    a = abs(a); b = abs(b);
    add_edge(a+k*(fa&1), b+k*(fb^1));
    add_edge(b+k*(fb&1), a+k*(fa^1));
}

void solve() {
    for (int i = 1; i < MAX; ++i) {
        g[i].clear();
        g2[i].clear();
    }
    cin >> k >> m;
    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y);
        add(y, z);
        add(z, x);
    }
    n = 2 * k;
    kosaraju();
    for (int i = 1; i <= k; ++i)
        if (color[i] == color[i+k]) {
            cout << "no" << endl;
            return;
        }
    cout << "yes" << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }    
    return 0;
}
