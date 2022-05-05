#include<bits/stdc++.h>
using namespace std;

struct FastIO {
    static const int S = 1e7;
    int wpos;
    char wbuf[S];
    FastIO() : wpos(0) {}
    inline int xchar() {
        static char buf[S];
        static int len = 0, pos = 0;
        if (pos == len)
            pos = 0, len = fread(buf, 1, S, stdin);
        if (pos == len) exit(0);
        return buf[pos++];
    }
    inline int xint() {
        int s = 1, c = xchar(), x = 0;
        while (c <= 32) c = xchar();
        if (c == '-') s = -1, c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x * s;
    }
    inline void wchar(int x) {
        if (wpos == S) fwrite(wbuf, 1, S, stdout), wpos = 0;
        wbuf[wpos++] = x;
    }
    inline void wstring(const char *s) {
        while (*s) wchar(*s++);
    }
    ~FastIO() {
        if (wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
} io;

struct matrix{
	int w, h;
	int mat[505][505];
} a, b, c, x, res1, res2, res3;

void mul(matrix &c, matrix &a, matrix &b) {
	c.w = a.w; c.h = b.h;
	for (int i = 1; i <= a.w; ++i)
		for (int j = 1; j <= b.h; ++j) c.mat[i][j]=0;
	for (int k = 1; k <= a.h; ++k)
		for (int i = 1; i <= c.w; ++i)
			for (int j = 1; j <= c.h; ++j)
				c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
}

int main() {
	srand(time(NULL));
	int T = io.xint();
	while (T--) {
		int n = io.xint();
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j) a.mat[i][j] = io.xint();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) b.mat[i][j] = io.xint();
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j) c.mat[i][j] = io.xint();
		a.w = a.h = b.w = b.h = c.w = c.h = n;
		for (int i=1;i<=n;++i) x.mat[i][1]=rand()%n+1;
		x.w=n; x.h=1;
		mul(res1, b, x);
		mul(res2, a, res1);
		mul(res3, c, x);
		bool flag=0;
        for (int i = 1; i <= n; ++i)
            if (res2.mat[i][1] != res3.mat[i][1]) {
                flag = 1;
                break;
            }
        if (flag) io.wstring("false\n");
        else io.wstring("true\n");
	}
}