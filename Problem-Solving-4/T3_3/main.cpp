#include <bits/stdc++.h>

using namespace std;

#define MAXN 30

int n;
int a[MAXN], b[MAXN], c[MAXN];
int num[MAXN], nxt[MAXN];
bool used[MAXN];

bool isValid() {
    for (int i = n - 1, x = 0; i >= 0; --i) {
        int A=num[a[i]], B=num[b[i]], C=num[c[i]];
        if ((A + B + x) % n != C) return false;
        x = (A + B + x) / n;
    }
    return true;
}

bool isPrune() {
    if (num[a[0]] + num[b[0]] >= n)
        return true;
    for (int i = n-1; i >= 0; --i) {
        int A=num[a[i]], B=num[b[i]], C=num[c[i]];
        if (A == -1 || B == -1 || C == -1) continue;
        if ((A + B) % n != C && (A + B + 1) % n != C) return true;
    }
    return false;
}

void dfs(int x) {
    if (isPrune()) return;
    if (x == n) {
        if(isValid()) {
            for (int i = 0; i < n; ++i)
            cout << num[i] << " ";
            exit(0);
        }
        else return;
    }

    for (int i = n - 1; i >= 0; --i)
        if (!used[i]) {
            num[nxt[x]] = i;
            used[i] = true;
            dfs(x + 1);
            num[nxt[x]] = -1;
            used[i] = false;
        }
    return;
}

int cnt;
void getNext(int x) {
    if (!used[x]) {
        used[x] = true;
        nxt[cnt++] = x;
    }
    return;
}

string sa, sb, sc;
int main() {
    cin >> n;
    cin >> sa >> sb >> sc;
    for (int i = 0; i < n; ++i) {
        a[i] = sa[i] - 'A';
        b[i] = sb[i] - 'A';
        c[i] = sc[i] - 'A';
        num[i] = -1;
    }

    for (int i = n - 1; i >= 0; --i) {
        getNext(a[i]);
        getNext(b[i]);
        getNext(c[i]);
    }
    memset(used, false, sizeof(used));
    dfs(0);
    return 0;
}