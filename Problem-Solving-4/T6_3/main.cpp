#include<bits/stdc++.h>

using namespace std;

#define N 5005
long long c[N][N], b[N];
int n, m;
long long pos[N];

int gauss()
{
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		int t = 0;
		for (int j = i;j<=n;j++)
		    if(c[j][i]) { t = j; break;}
		if(t==0) { cnt++; continue;}
		for(int k = 1; k <= n; ++k)
		    swap(c[i][k], c[t][k]);
		swap(b[i], b[t]);
		cnt++;
		for (int j = 1; j <= n; ++j)
		{
			if (j == i || !c[j][i]) continue;
			for (int k = i+1; k <= n; ++k)
			    c[j][k] ^= c[i][k];
			b[j] ^= b[i];
			c[j][i] = 0;
		}
	}
	return cnt;
}

long long ans = 1e9;
long long light[N];
void dfs(int x, long long cnt)
{
	if (cnt >= ans) return;
	if (x == 0)
	{
		ans = cnt;
		return;
	}
	if (c[x][x])
	{
		long long val = b[x];
		for (int i = x+1; i <= n; ++i)
		if (c[x][i]) val ^= light[i];
		dfs(x-1, cnt+val);
	}
    else
	{
		dfs(x-1, cnt);
		light[x] = 1;
		dfs(x-1, cnt+1);
		light[x] = 0;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		c[i][i] = 1;
		b[i] = 1;
	}
	for(int i = 1; i <= m; ++i)
	{
		int x, y;
		cin >> x >> y;
		c[x][y] = c[y][x] = 1;
	}
	if (gauss() == 0)
	{
		long long ans=0;
		for (int i = 1; i <= n; ++i)
		ans += b[i];
		cout << ans << endl;
		return 0;
	}
	dfs(n, 0);
	cout << ans << endl;; 
	return 0;
}