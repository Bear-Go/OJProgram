#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;

int n, m, k;

class DSU {
public:
    int pre[MAXN + 50], val[MAXN + 50];
    void init(int N) {
        for (int i = 1; i <= N; i++) {
            pre[i] = i;
            val[i] = 0;
        }
    }
    int find_anc(int x) {
        if (x == pre[x]) return x;
        int fa = pre[x];
        pre[x] = find_anc(pre[x]);
        val[x] += val[fa];
        return pre[x];
    }
    bool update(int x, int y, int c) {
        int fx = find_anc(x), fy = find_anc(y);
        if (fx != fy) {
            pre[fx] = fy;
            val[fx] = -val[x] + c + val[y];
        }
        else
            if (c + val[y] != val[x]) return false;
        return true;
    }
};

int main() {
    int ca;
    cin >> ca;
    while (ca--) {
        DSU dsu;
        cin >> n >> m >> k;
        dsu.init(n + m);
        int x, y, c;
        bool f = true;
        for (int i = 1; i <= k; i++) {
            cin >> x >> y >> c;
            if (!dsu.update(x, n + y, c)) f = false;
        }
        cout << (f ? "Yes" : "No") << endl;
    }
    return 0;
}