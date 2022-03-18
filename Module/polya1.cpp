#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll p = 1e9+7;

ll binpow(ll a, ll b) {
    a %= p;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

ll phi(ll n) {
    ll ans = n;
    for (ll i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            ans = ans / i * (i - 1);
            while (n % i == 0) n /= i;
        }
    if (n > 1) ans = ans / n * (n - 1);
    return ans;
}

ll n, m, ans = 0;
int main() {
    cin >> n >> m;
    for (ll i = 1; i * i <= n; ++i) 
        if (n % i == 0) {
            ans = (ans + binpow(m, i) * phi(n / i)) % p;
            if (i * i != n) 
                ans = (ans + binpow(m, n/i) * phi(i)) % p;
        }
    ans = ans * binpow(n, p - 2) % p;
    cout << ans << endl;
    return 0;
}
