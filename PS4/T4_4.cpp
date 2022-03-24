#include<bits/stdc++.h>
#define M 100005
using namespace std;

int n,m,root,cnt,tot;
struct edge{
	int v, w, next;
} e[M << 1];
int first[M], pos[M], st[18][M << 1], BI[M << 1], sum[M];

void add(int x,int y,int z) {
	e[++tot].v = y; e[tot].w = z; e[tot].next = first[x]; first[x] = tot;
	e[++tot].v = x; e[tot].w = z; e[tot].next = first[y]; first[y] = tot;
}

void dfs(int x,int fa) {
	pos[x] = ++cnt;
	st[0][cnt] = x;
	for (int i = first[x]; i; i = e[i].next)
		if (fa != e[i].v) {
			sum[e[i].v] = sum[x] + e[i].w;
			dfs(e[i].v, x);
			st[0][++cnt] = x;
        }
}

int lca(int x,int y) {
	x = pos[x]; y = pos[y];
	if (x > y) swap(x, y);
	int t = BI[y - x + 1], xx, yy;
	xx = st[t][x]; yy = st[t][y - (1 << t) + 1];
	if (pos[xx] > pos[yy]) return yy;
	else return xx;
}

int main() {
    cin >> n >> m;
	root = 1;
	int x, y, z;
	for (int i = 1; i < n; ++i) {
        cin >> x >> y >> z;
		add(x, y, z);
	}
	dfs(root, 0);
	BI[1] = 0;
	for (int i = 2; i <= cnt; ++i) 
        BI[i] = BI[i >> 1] + 1;
	for (int i = 1; (1 << i) <= cnt; ++i)
		for (int j = 1; (1 << i) + j - 1 <= cnt; ++j) {
			x = st[i-1][j];
			y = st[i-1][j+(1<<i-1)];
			if (pos[x] < pos[y]) st[i][j] = x;
			else st[i][j] = y;
		}
    while (m--) {
        cin >> x >> y;
        cout << sum[x] + sum[y] - 2 * sum[lca(x, y)] << endl;
    }
    return 0;
}