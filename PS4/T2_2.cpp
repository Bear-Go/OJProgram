#include <iostream>
#define N 20
#define inf 1000000007
using namespace std;

int n, a[N][N], dp[N][1 << N], ans = inf;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++ i)
        for (int j = 0; j < n; ++ j)
            cin >> a[i][j];

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    for (int i = 0; i < n; ++ i)
        for (int s = 0; s < (1 << n); ++ s)
           dp[i][s] = inf;

    for (int i = 0; i < n; ++ i) dp[i][1 << i] = 0;

    for (int s = 0; s < (1 << n); ++ s)
        for (int i = 0; i < n; ++ i) {
            if (!((s >> i) & 1)) continue;
            for (int j = 0; j < n; ++ j) {
                int ss = s | (1 << j);
                dp[j][ss] = min(dp[j][ss], dp[i][s] + a[i][j]);
            }
        }
    for (int i = 0; i < n; ++ i) ans = min(ans, dp[i][(1 << n) - 1]);
    cout << ans;
    return 0;
}