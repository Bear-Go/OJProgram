#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, m;
int A[MAXN], ans[MAXN];

struct node
{
    int op, pos, id;
    bool operator < (const node &other) const {return pos > other.pos;}
} q[MAXN];

set<pair<int,int>> s;

int main ()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> A[i];
    for (int i = 1; i <= m; ++i) {
        cin >> q[i].op >> q[i].pos;
        q[i].id=i;
    }
    sort(q + 1, q + m + 1);
    int ptr = n;
    for (int i = 1; i <= m; ++i) {
        while (ptr > q[i].pos) {
            set<pair<int, int>>::iterator iter = s.lower_bound(make_pair(A[ptr], ptr));
            if (iter != s.end() && iter->first == A[ptr]) s.erase(iter);
            s.insert(make_pair(A[ptr], ptr));
            ptr--;
        }
        set<pair<int, int>>::iterator iter = s.lower_bound(make_pair(A[q[i].pos], q[i].pos));
        if (q[i].op == 0) {
            if (iter!=s.end()) ans[q[i].id] = iter->second;
            else ans[q[i].id] = -1;
        }
        else {
            if (iter != s.end() && iter->first == A[q[i].pos]) ans[q[i].id] = iter->second;
            else if (iter == s.begin()) ans[q[i].id] = -1;
            else {
                --iter;
                ans[q[i].id] = iter->second;
            }
        }
    }
    for (int i = 1; i <= m; ++i) cout << ans[i] << endl;
    return 0;
}