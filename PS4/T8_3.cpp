#include<bits/stdc++.h>
#define MNUM 1000005
#define mod 1000000007
using namespace std;
typedef long long ll;

struct node{
	ll pos, sor, max, min;
} S[MNUM];

ll a[MNUM], A[MNUM], B[MNUM], C[MNUM], D[MNUM];
ll ans[MNUM];

int main() {
    int T, n;
    cin >> T;
	while (T--) {
        cin >> n;
		ll x, y, z, cnt, id;
        memset(ans, 0, sizeof(ans));
        cin >> a[1] >> a[2] >> x >> y >> z;
		for (int i = 3; i <= n; ++i) 
            a[i] = (a[i-1]*y + a[i-2]*x + z) % 1000000 + 1;
		node t;
		cnt = 0;
		for (int i = 1; i <= n; ++i) {
			t = (node){i, a[i], a[i], a[i]};
			while (cnt && S[cnt].min >= a[i]) {
				t.sor |= S[cnt].sor;
				t.max = max(t.max, S[cnt].max);
				--cnt;
            }
			A[i] = t.max; 
            B[i] = a[i];
            C[i] = i - S[cnt].pos;
            D[i] = t.sor;
			S[++cnt]=t;
		}
		cnt = 0;
		for (int i = n; i >= 1; --i) {
			t = (node){i, a[i], a[i], a[i]};
			while (cnt && S[cnt].min >= a[i]) {
				t.sor |= S[cnt].sor;
				t.max = max(t.max, S[cnt].max);
				--cnt;
            }
			A[i] = max(A[i], t.max);
            C[i] += (!cnt ? n+1-i : S[cnt].pos-i)-1;
            D[i] |= t.sor;
			S[++cnt] = t;
		}
		for (int i = 1; i <= n; ++i)
            ans[C[i]] = max(ans[C[i]], a[i]*(A[i]-a[i])*D[i]);
		ll val = ans[1], len=1;
		for (int i = 2;i <= n; ++i)
			if (val/i <= ans[i]/len) val = ans[i], len=i;
		cout << (val % mod) * len % mod << endl;
	}
    return 0;
}