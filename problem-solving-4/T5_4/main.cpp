#include<bits/stdc++.h>

using namespace std;

int n, m;
long long a[20005], b[20005];
long long dp[10005];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
	sort(a+1, a+n+1);
	sort(b+1, b+m+1);

	memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i) 	
	    for (int j = min(i,m); j >= 1; --j)
            dp[j] = (i > j) ? min(dp[j], dp[j-1] + abs(a[i]-b[j])) : dp[j-1] + abs(a[i]-b[j]);
    cout << dp[m] << endl;
}