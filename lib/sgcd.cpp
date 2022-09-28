#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void getPrimeFactors(ll result[], ll n) {
    if (n == 1) {result[0] = 1; return;}
    ll cnt = 0;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            result[cnt++] = i;
            while (n % i == 0) n /= i;
        }
    }
    if (n != 1) result[cnt] = n; 
}

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}


ll n, a1;
ll factors[100];
void solve() {
    cin >> n >> a1;
    getPrimeFactors(factors, a1);
    n -= 1;
    cout << a1 / factors[0] << " ";
    while (n--) {
        ll ai;
        cin >> ai;
        ll t = gcd(a1, ai);
        ll cnt = 0;
        for (; factors[cnt] != 0; ++cnt)
            if (t % factors[cnt] == 0) {
                cout << t / factors[cnt] << " ";
                break;
            }
        if (factors[cnt] == 0) cout << -1 << " ";
    }
}

int main() {
    solve();
}