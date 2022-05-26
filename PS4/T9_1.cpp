#include<bits/stdc++.h>

using namespace std;

int n, m;
int A[1005];

// naive solution O(n^2)
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> A[i];
    for (int i = 1; i <= m; ++i) {
        int choice, p;
        cin >> choice >> p;
        int val = A[p];
        if (choice == 0) {
            int min_A = INT_MAX;
            int q = p;
            for (int j = p + 1; j <= n; ++j) {
                if (A[j] >= val) {
                    if (A[j] < min_A) {
                        min_A = A[j];
                        q = j;
                    }
                }
            }
            if (q == p) cout << -1 << endl;
            else cout << q << endl;
        } else {
            int max_A = INT_MIN;
            int q = p;
            for (int j = p + 1; j <= n; ++j) {
                if (A[j] <= val) {
                    if (A[j] > max_A) {
                        max_A = A[j];
                        q = j;
                    }
                }
            }
            if (q == p) cout << -1 << endl;
            else cout << q << endl;
        }
    }
    return 0;
}