#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 9;

int n, m, k, d;
int ga[50][50];

struct Matrix {
    int b[50][50];
    void init() {memset(b, 0, sizeof(b));}
    void init_I() {init(); for (int i = 1; i <= n; ++i) b[i][i] = 1;}
    int sum() {
        int res = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                res = (res + b[i][j]) % MOD;
        return res;
    }
    Matrix operator + (Matrix other) {
        Matrix res;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                res.b[i][j] = (b[i][j] + other.b[i][j]) % MOD;
        return res;
    }
    Matrix operator * (Matrix other) {
        Matrix res; res.init();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                for (int k = 1; k <= n; ++k)
                    res.b[i][j] = (res.b[i][j] + 1ll * b[i][k] * other.b[k][j] % MOD) % MOD;
        return res;
    }
} trans;

Matrix quick_pow(Matrix x, int y) {
    Matrix res; res.init_I();
    while (y) {
        if (y & 1) res = res * x;
        x = x * x;
        y >>= 1;
    }
    return res;
}

bool check_valid(int x, int Mask) {
    if (x > k) return true;
    if (Mask & (1 << (x - 1))) return false;
    return true;
}

int main(){
    cin >> n >> m >> k >> d;
    int x, y;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        ga[x][y] = ga[y][x] = 1;
    }
    if (d == 1) {
        switch(k) {
            case 0:  cout << n; break;
            case 1:  cout << 1; break;
            default: cout << 0; break;
        }
        return 0;
    }
    int ans = 0;
    for (int Mask = 0; Mask <= (1 << k) - 1; ++Mask) {
        trans.init();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                trans.b[i][j] = (check_valid(i, Mask) && check_valid(j, Mask)) ? ga[i][j] : 0;
        int res = quick_pow(trans, d - 1).sum();
        if (__builtin_popcount(Mask) & 1)
            if (ans < res) ans = ans - res + MOD;
            else ans = ans - res;
        else 
            ans = (ans + res) % MOD;
    }
    cout << ans << endl;
    return 0;
}