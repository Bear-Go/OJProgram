#include <bits/stdc++.h>

using namespace std;

#define MAXN 50005
int a[MAXN];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 2; i++)
        for (int j = i + 2; j < n; j++)
            if (a[i] == a[j]) 
            {
                cout << "YES" << endl;
                return;
            }
    cout << "NO" << endl;
}

int main() 
{
    int T;
    cin >> T;
    while (T--) 
        solve();
}