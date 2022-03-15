#include <bits/stdc++.h>
using namespace std;

#define MAX 3100000
const double pi = acos(-1);
struct Complex {
    double r,i;
    Complex(double _r = 0, double _i = 0) {r = _r; i = _i;}
    Complex operator +(const Complex &b) {return Complex(r + b.r, i + b.i);}
    Complex operator -(const Complex &b) {return Complex(r - b.r, i - b.i);}
    Complex operator *(const Complex &b) {return Complex(r * b.r - i * b.i, r * b.i + i * b.r);}
};
Complex a[MAX], b[MAX]; 
int base[MAX], lf[MAX], rf[MAX], s[MAX];

void change(Complex y[], int len){
    int i, j, k;
    for (i = 1, j = len / 2; i < len - 1; ++i) {
        if (i < j) swap(y[i], y[j]);
        k = len / 2;
        while (j >= k) j -= k, k /= 2;
        if (j < k) j += k;
    }
}

void fft(Complex y[], int len, int on) {
    change(y, len);
    for (int h = 2; h <= len; h <<= 1) {
        Complex wn(cos(-on * 2 * pi / h), sin(-on * 2 * pi / h));
        for (int j = 0; j < len; j += h) {
            Complex w(1, 0);
            for (int k = j; k < j + h / 2; ++k) {
               Complex u = y[k], t = w * y[k + h / 2];
                y[k] = u + t;
                y[k + h / 2] = u - t;
                w = w * wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0; i < len; ++i)
            y[i].r /= len;
}
char c1[(1<<19)+5];
int len, tt, rlen;
void init() {
	scanf("%s",&c1);
	len = strlen(c1);
	tt = log2(len);
	rlen = (rlen == (1<<tt) ? len : 1 << (tt + 1)); 
	for (int i = 0; i < len / 2; ++i) 
	    swap(c1[i], c1[len - i - 1]);
    for(int i = len; i < rlen; ++i)
    	c1[i] = '0';
}

int mult(int *a1, int *b1, int lena, int lenb)
{
		int size = log2(lena + lenb) + 1;
		int len = 1 << size;
		for (int i = 0; i < lena; ++i) 
		    a[i].r = a1[i], a[i].i = 0;
		for (int i = lena; i < len; ++i)
		    a[i].r = 0, a[i].i = 0;
		for (int i = 0; i < lenb; ++i) 
		    b[i].r = b1[i], b[i].i = 0;
		for (int i = lenb; i < len; ++i) 
		    b[i].r = 0, b[i].i = 0;
		fft(a, len, 1);   fft(b, len, 1);
		for (int i = 0; i < len; ++i) a[i] = a[i] * b[i];
        fft(a, len, -1);
		for (int i = 0; i < len; ++i)
		    a1[i] = (int)(a[i].r + 0.5);
		while (len > 1 && a1[len - 1] == 0) --len;
		int cf = 0;
		for (int i = 0; i < len; ++i)
			a1[i] += cf, cf = (a1[i])/27, (a1[i]) %= 27;
		while (cf)
			a1[len++] = cf, cf = a1[len - 1] / 27, a1[len - 1] %= 27;
		return len;
}
int getbase(int n) {
	if ( n <= 16) {
		int len = 0;
		long long t = 1;
		for (int i = 1; i <= n; ++i) t *= 10;
		do {base[len++] = t % 27; t /= 27;} while (t);
		return len;
	}
	int len = getbase(n / 2);
	return mult(base, base, len, len);
}
int trans(int l, int r) {
	int tot1 = 0;
    if (r - l <= 2) {
   	    int now = 0;
   	    for (int i = r; i >= l; --i) now = now * 10 + (c1[i] - '0');
   	    while (now != 0) 
	        s[tot1] = now % 27, tot1++, now /= 27;
	    return tot1;
    }
    int mid = (l + r) / 2;
    int totlf = trans(l, mid);
    for (int i = 0; i < totlf; ++i)
    	lf[i] = s[i];
	vector<int> loadlf;
	for (int i = 0; i < totlf; ++i) loadlf.push_back(lf[i]);
    int totrf = trans(mid + 1, r);
	for (int i = 0; i < totlf; ++i) lf[i] = loadlf[i];
    for (int i = 0;i < totrf; ++i) rf[i] = s[i];
    int lbase = getbase(r - mid);
    totrf = mult(rf, base, totrf, lbase);
    tot1 = max(totrf, totlf);
    int cf = 0;
	for (int i = 0; i < tot1; ++i) {
		if (i >= totrf) rf[i] = 0;
		else if (i >= totlf) lf[i] = 0;
		s[i] = cf + rf[i] + lf[i];
	    cf = s[i] / 27;
		s[i] %= 27;
	}
	while (cf != 0) {
		s[tot1++] = cf;
		cf = s[tot1 - 1] / 27;
		s[tot1 - 1] %= 27;
	}
	return tot1;
}
int main() {
	init();
	int anslen = trans(0, rlen - 1);
	if(s[anslen - 1] >= 9)
		printf("%d%d%d", s[anslen - 1] / 9, (s[anslen - 1] / 3) % 3, s[anslen - 1] % 3);
	else if(s[anslen - 1] >= 3)
		printf("%d%d", (s[anslen - 1] / 3), s[anslen-1] % 3);
	else 
        printf("%d", s[anslen - 1]);
	for (int i = anslen - 2; i >= 0; --i)
		printf("%d%d%d", s[i] / 9,(s[i] / 3) % 3, s[i] % 3);
	return 0;
}