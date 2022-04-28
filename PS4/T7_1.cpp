#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int a[1005];

int dp[2][1005];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i) 
            cin >> a[i];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                dp[i % 2][j] = dp[(i - 1) % 2][j];
                if (j >= a[i]) {
                    dp[i % 2][j] = (dp[i % 2][j] + dp[(i - 1) % 2][j - a[i]]) % mod;
                }
            }
        }
        cout << dp[n % 2][k] << endl;
    }
}

/* recursion */

int solve(int n, int k) {

    int sum = 0;
    if (n == 0) {
        return (k == 0) ? 1 : 0;
    }
    /* case 1: a_n is selected */
    if (a[n] <= k) sum += solve(n - 1, k - a[n]);
    /* case 2: a_n is not selected */
    if (n > 0) sum += solve(n - 1, k);
    return sum % mod;
}

/* naive solution */
/*
int main() 
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, k, ans;
        cin >> n >> k;
        queue<int> q;
        q.push(0);
        ans = (k == 0) ? 1 : 0;
        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            int q_size = q.size();
            while (q_size--)
            {
                int sum = q.front();
                q.pop();
                q.push(sum);
                if (sum + a < k)
                    q.push(sum + a);
                if (sum + a == k)
                {
                    q.push(sum + a);
                    ans++;
                    if (ans >= mod)
                        ans -= mod;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
*/