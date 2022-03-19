#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int n;
int x[MAXN], y[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    if (n % 2) cout << x[n / 2 + 1] << " " << y[n / 2 + 1] << endl;
    else cout << x[n / 2] << " " << y[n / 2] << endl;
    return 0;
}