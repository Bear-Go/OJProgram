#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
const ll mod = 1e9 + 7;
 
int main() {
    int n, h[101];
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> h[i];
    int mn = *min_element(h + 1, h + n + 1);
    ll dp[1001], pref[1001], ans = 0;
    do { 
        for (int i = 0; i <= h[1]; ++i) 
            pref[i] = i + 1;
        for (int i = h[1] + 1; i <= 1000; ++i) 
            pref[i] = h[1] + 1;
        for (int i = 2; i <= n; ++i) {
            memset(dp, 0, sizeof dp);
            for (int j = 0; j <= h[i]; ++j) {
                dp[j] = pref[h[i] - j];
                dp[j] = (dp[j] >= mod ? dp[j] - mod : dp[j]);
            }
            for (int j = 0; j <= 1000; ++j) {
                pref[j] = dp[j];
                pref[j] = (j) ? (pref[j] + pref[j - 1]) : pref[j];
                pref[j] = (pref[j] >= mod ? pref[j] - mod : pref[j]);
            }
        }
        ans += pref[0];
        ans = (ans >= mod ? ans - mod : ans);
        for (int i = 1; i <= n; ++i) 
            --h[i];
    } while (n % 2 && mn--);
    cout << ans << endl;
    return 0;
}