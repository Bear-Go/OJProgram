#include <bits/stdc++.h>
using namespace std;

int lev[11][11];

int get_lev(string a, string b) {
	int len1 = a.length(), len2 = b.length();
	memset(lev, 0, sizeof(lev));
	for (int i = 0; i <= len1; i++) lev[i][0] = i;
	for (int i = 0; i <= len2; i++) lev[0][i] = i;
	for (int i = 1; i <= len1; i++)
		for (int j = 1; j <= len2; ++j) {
			if (a[i-1] == b[j-1]) 
                lev[i][j] = lev[i-1][j-1];
			else 
                lev[i][j] = lev[i-1][j-1] + 1;
			lev[i][j] = min(lev[i][j], min(lev[i][j-1] + 1, lev[i-1][j] + 1));
		}
	return lev[len1][len2];
}

vector<string> s;
int d[101][101];
bool visited[101];
int min_cost[101];

int prim(int V) {
	for (int i = 0; i < V; ++i) min_cost[i] = 0x3fffffff;
	memset(visited, 0, sizeof(visited));
	min_cost[0] = 0;
	int res = 0;
	while (1) {
		int v = -1;
		for (int u = 0; u < V; ++u)
			if (!visited[u] && (v == -1 || min_cost[u] < min_cost[v])) v = u;
		if (v == -1) break;
		visited[v] = true;
		res += min_cost[v];
		for (int u = 0; u < V; ++u)
			min_cost[u] = min(min_cost[u], d[v][u]);
	}
	return res;
}

int main() {
	int T, n;
    cin >> T;
	while (T--) {
        cin >> n;
		s.clear();
		memset(d, 0, sizeof(d));
		for (int i = 0; i < n; ++i) {
			string tmp;
			cin >> tmp;
			s.push_back(tmp);
			for (int j = 0; j < i; j++) {
				d[j][i] = get_lev(s[i], s[j]);
				d[i][j] = d[j][i];
			}
		}
		int ans = 2 * prim(n);
        cout << ans << endl;
	}
}