#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define N 100000000

static bool is_prime[N];
static ll primes[N];

ll *sieveEratosthenes(ll n) {
    for (ll i = 0; i < (n >> 1) - 1; ++i)
        is_prime[i] = true;

    for (ll i = 0, num = 3; num * num < n; ++i, num = (i << 1) + 3)
        if (is_prime[i])
            for (ll t = num * num; t < n; t += (num << 1))
                is_prime[(t >> 1) - 1] = false;

    primes[0] = 2;
    for (ll i = 0, cnt = 1; i < (n >> 1) - 1; ++i)
        if (is_prime[i]) primes[cnt++] = (i << 1) + 3;
    
    return primes;
}

static bool is_coprime[N];
static ll coprimes[N];

ll *getCoPrimes(ll n) {
    for (ll i = 2; i < n; ++i)
        is_coprime[i] = true;
    for (ll i = 2; i * i < n; ++i)
        if (is_coprime[i] && n % i == 0) {
            is_coprime[i] = false;
            for (ll j = i * i; j < n; j += i)
                is_coprime[j] = false;
        }
    coprimes[0] = 1;
    for (ll i = 2, cnt = 1; i < n; ++i) {
        if (is_coprime[i]) coprimes[cnt++] = i;
    }
    return coprimes;
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

ll *sieveEuler(ll n) {
    for (ll i = 0; 2 * i < n; ++i)
        is_prime[i] = true;
    primes[0] = 2;
    ll cnt = 1;
    for (ll i = 0, num = 3; num < n; num = ((++i) << 1) + 3) {
        if (is_prime[i]) primes[cnt++] = num;
        for (ll j = 1; j < cnt; ++j) {
            ll t =  num * primes[j];
            if (t < n) {
                is_prime[(t - 3) >> 1] = false;
                if (num % primes[j] == 0) break;
            }
            else break;
        }
    }
    return primes;
}

void test() {

}

void runSieve() {
    ll n;
    printf("Target: primes less than N\nInput N: ");
    scanf("%d", &n);
    ll *primes = sieveEuler(n);
    printf("Primes table\n");
    for (ll *cur = primes, i = 0; *cur; ++cur, ++i) {
        printf("%6d", *cur);
        if (i % 8 == 7 || !*(cur + 1)) printf("\n");
    }
}

void runCoprime() {
    ll n;
    printf("Target: co-primes of N\nInput N: ");
    scanf("%d", &n);
    ll *coprimes = getCoPrimes(n);
    printf("CoPrimes table\n");
    for (ll *cur = coprimes, i = 0; *cur; ++cur, ++i) {
        printf("%6d", *cur);
        if (i % 8 == 7 || !*(cur + 1)) printf("\n");
    }
}

void runPhi() {
    ll n;
    printf("Target: euler-phi(n)\nInput n: ");
    scanf("%d", &n);
    ll ans = phi(n);
    printf("Euler-phi(%d) = %d\n", n, ans);
}

void tst() {
    int n, q;
    cin >> n >> q;
	ll *primes = sieveEuler(n);
	while (q--) {
		int k;
		cin >> k;
		cout << primes[k - 1] << endl;
	}
}

int main() {
    runSieve();
}