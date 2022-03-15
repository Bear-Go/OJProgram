#include <bits/stdc++.h>

using namespace std;

bool isPrime(long long n) {
    for (long long i = 2; i * i <= n; ++i )
        if (n % i==0) return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << ((isPrime(n)) ? "true":"false") << endl;
    }
}