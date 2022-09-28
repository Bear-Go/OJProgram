#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 1e6+1;
ll l, r;
int prime[maxn], cnt, ans;
bool vis[maxn];

void getPrimes() {
    for (int i = 2; i <= 50000; ++i) {
        if (!vis[i]) prime[++cnt]=i;
        for (int j = 1; i * prime[j] <= 50000; ++j) {
            vis[i*prime[j]] = 1;
            if (i%prime[j] == 0) break;
        }
    }
}

int main() {
    cin >> l >> r;
    l = (l == 1) ? 2 : l;
    getPrimes();
    memset(vis, 0, sizeof(vis));
    for (int i = 1 ; i <= cnt; ++i) {
        ll p = prime[i];
        ll start = ((l+p-1)/p*p>2*p) ? (l+p-1)/p*p : 2*p;
        for(ll j = start; j <= r; j += p)
            vis[j-l+1] = 1;
    }
    for (int i = 1; i <= r-l+1; ++i) if (!vis[i]) ans++;
    cout << ans << endl;
}