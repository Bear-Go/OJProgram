#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int cnt = 1;
    int sum = n * m;

    cout << x << " " << y << endl;
    if (n % 2 == 0) {
        while (cnt < sum) {
            if (y == 0) {
                if (x <= n-2) x++;
                else y++;
            }
            else {
                if (x % 2 == 0) {
                    if (x == 0) {
                        if (y > 0) y--;
                    }
                    else if (y > 1) y--;
                    else x--;
                }
                else {
                    if (y < m-1) y++;
                    else x--;
                }
            }
            cout << x << " " << y << endl;
            cnt++;
        }
    }
    else {
        while (cnt < sum) {
            if (x == 0) {
                if (y <= m-2) y++;
                else x++;
            }
            else {
                if (y % 2 == 0) {
                    if (y == 0) {
                        if (x > 0) x--;
                    }
                    else if (x > 1) x--;
                    else y--;
                }
                else {
                    if (x < n-1) x++;
                    else y--;
                }
            }
            cout << x << " " << y << endl;
            cnt++;
        }
    }

    return 0;
}