#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll qmul(ll a, ll b, ll m) {
    ll ans = 0;
    while (b) {
        if (b & 1) ans = (ans + a) % m;
        a = (a << 1) % m;
        b >>= 1;
    }
    return ans;
}

ll powermod(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b) {
        if (b & 1) res = qmul(res, a, m);
        a = qmul(a, a, m);
        b >>= 1;
    }
    return res;
}

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void naive_encode(ll n, ll E, ll x) {
    ll buf[100], cnt = 0;
    while (x) {
        ll t = x % 100;
        buf[cnt++] = binpow(t, E, n);
        x /= 100;
    }
    for (-- cnt; cnt >= 0; --cnt)
        cout<<buf[cnt];
    cout<<endl;
}

void naive_decode(ll n, ll D, ll y) {
    cout<<binpow(y, D, n)<<endl;
}

int main() {
    while (1) {
        ll a, b, m;
        cin>>a>>b>>m;
        cout<<binpow(a, b, m);
    }
}