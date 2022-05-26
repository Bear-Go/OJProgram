#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n,m;
int a[MAXN];

set<int> s;
int maxn[MAXN];
long long dp[MAXN];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    s.insert(0); 
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        if (maxn[a[i]] != 0) s.erase(-maxn[a[i]]);
        maxn[a[i]] = i; 
        s.insert(-i); 
        int cnt = 0; 
        dp[i] = 1e16;
        for (set<int>::iterator iter = s.begin(); cnt * cnt < n && iter != s.end(); ++iter, ++cnt) {
            if (-*iter == i) continue;
            dp[i] = min(dp[i], dp[-*iter] + 1ll * cnt * cnt);
        }
    }
    cout << dp[n] << endl;
    return 0;
}