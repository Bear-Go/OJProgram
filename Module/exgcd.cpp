#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll exgcdrecur(ll a, ll b, ll &r, ll &s) {
    if (b == 0) {
        r = 1; s = 0;
        return a;
    }
    ll gcd = exgcdrecur(b, a%b, r, s);
    ll t = r;
    r = s;
    s = t - a/b * s;
    return gcd;
}

ll exgcditer(ll a, ll b, ll &r, ll &s) {
    r = 1, s = 0;
    ll r1 = 0, s1 = 1, a1 = a, b1 = b;
    while (b1) {
        ll q = a1 / b1;
        tie(r, r1) = make_tuple(r1, r - q * r1);
        tie(s, s1) = make_tuple(s1, s - q * s1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

void decode(ll n, ll &p, ll &q) {
    q = sqrt(n);
    while (n % q != 0) ++q;
    p = n / q;
}

void test() {

}

void run() {
    ll t;
    printf("Input the number of (a, b) you want to cal: ");
    scanf("%d", &t);
    while (t--) {
        ll a, b;
        printf("Input a and b: ");
        scanf("%d %d", &a, &b);
        ll x, y;
        ll gcd = exgcditer(a, b, x, y);
        printf("The answer to exgcd(a, b) is %d * %d + %d * %d = %d\n", a, x, b, y, gcd);
    }
}

int main() {
    run();
}