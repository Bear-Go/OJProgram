#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define N 20

struct exp {
    ll base, index;
    exp(ll _base = 0, ll _index = 0) {base = _base; index = _index;}
};

void getPrimeFactors(struct exp result[], ll n) {
    if (n == 1) {result[0] = {1, 1}; return;}
    ll cnt = 0;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            result[cnt] = {i, 0};
            while (n % i == 0) n /= i, ++result[cnt].index;
            ++cnt;
        }
    }
    if (n != 1) result[cnt] = {n, 1}; 
}

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void run() {
    ll n;
    cout << "Target: get prime factors of n: ";
    cin >> n;
    struct exp pf[N];
    getPrimeFactors(pf, n);
    cout << "n = ";
    for (ll cnt = 0; pf[cnt].base != 0; ++cnt)
        for (ll i = 1; i <= pf[cnt].index; ++i) 
            cout << pf[cnt].base << " ";
    cout << endl;
}

map<ll, ll> table;
void solve() {
    ll n, k, sum = 0;
    cin >> n >> k;
    while (n--) {
        ll t;
        cin >> t;
        struct exp pf[N];
        getPrimeFactors(pf, t);
        ll b = 1, c = 1;
        for (ll cnt = 0; pf[cnt].base != 0; ++cnt) {
            pf[cnt].index %= k;
            b *= qpow(pf[cnt].base, pf[cnt].index);
            c *= qpow(pf[cnt].base, (k - pf[cnt].index) % k);
        }
        map<ll, ll>::iterator iter = table.find(c);
        if (iter != table.end()) sum += iter->second;
        iter = table.find(b);
        if (iter != table.end()) iter->second += 1;
        else table.insert(pair<ll, ll> (b, 1));
    }
    cout << sum << endl;
}

int main() {
    solve();
}