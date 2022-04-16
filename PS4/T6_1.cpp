#include <bits/stdc++.h>

using namespace std;

int n;

typedef struct e {
    int x;
    long long w;
} e;

vector<e> edge[100005];
bool is_visited[100005];
long long d[100005];

void dfs(int u) 
{
    is_visited[u] = true;
    for (int i = 0; i < edge[u].size(); i++) {
        int v = edge[u][i].x;
        if (!is_visited[v]) {
            d[v] = d[u] + edge[u][i].w;
            dfs(v);
        }
    }
}

long long d_max;
int d_max_index;

int main()
{
    cin >> n;
    for (int i = 1; i <= n - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    memset(is_visited, false, sizeof(is_visited));
    memset(d, 0, sizeof(d));
    dfs(1);
    d_max = 0; d_max_index = 1;
    for (int i = 1; i <= n; ++i)
    {
        if (d[i] > d_max)
        {
            d_max = d[i];
            d_max_index = i;
        }
    }
    memset(is_visited, false, sizeof(is_visited));
    memset(d, 0, sizeof(d));
    dfs(d_max_index);
    d_max = 0;
    for (int i = 1; i <= n; ++i)
        d_max = max(d_max, d[i]);
    cout << d_max << endl;
    return 0;
}