#include<bits/stdc++.h>
using namespace std;

map<int, int> f;
int n, a[500005];

void solve()
{
	f.clear();
	cin >> n;
	int flag = 0;
	for (int i = 1; i <= n; ++i)
    {
		cin >> a[i];
		if (!f[a[i]]) f[a[i]] = i;
		if (f[a[i]] != 0 && f[a[i]] < i-1) flag = 1;
	}
	if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}