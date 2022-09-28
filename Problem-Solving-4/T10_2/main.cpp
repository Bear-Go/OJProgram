#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4;

int n, m;

class DSU {
public:
    int pre[MAXN + 50], val[MAXN + 50];
    void init() {
        for (int i = 0; i <= n; i++) {
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
        cin >> n >> m;
        dsu.init();
        int x, y, c;
        bool f = true;
        for (int i = 1; i <= m; i++) {
            cin >> x >> y >> c;
            if (!dsu.update(y, x - 1, c)) f = false;
        }
        cout << (f ? "true" : "false") << endl;
    }
    return 0;
}