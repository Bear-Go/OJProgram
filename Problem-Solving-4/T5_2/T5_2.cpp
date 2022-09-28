#include<bits/stdc++.h>

using namespace std;

typedef struct point
{
    long long x, y;
} point;
 
double multi(point a, point b, point c)
{
    return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}

bool is_intersect(point a, point b, point c, point d)
{
    if ( max(a.x, b.x) < min(c.x, d.x) ) return false;
    if ( max(a.y, b.y) < min(c.y, d.y) ) return false;
    if ( max(c.x, d.x) < min(a.x, b.x) ) return false;
    if ( max(c.y, d.y) < min(a.y, b.y) ) return false;
    if ( multi(c, b, a)*multi(b, d, a) < 0 ) return false;
    if ( multi(a, d, c)*multi(d, b, c) < 0 ) return false;
    return true;
}

int n;
point points[2005];
int m[1005];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
    {
        cin >> points[2*i-1].x;
        cin >> points[2*i-1].y;
        cin >> points[2*i].x;
        cin >> points[2*i].y;
    }
	for (int i = 2; i <= n; ++i)
    {
		for (int j = 1; j < i; ++j)
        {
			if(is_intersect(points[2*i-1], points[2*i], points[2*j-1], points[2*j]))
				m[j] = 1;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) ans += !m[i];
	cout << ans << endl;
	return 0;
}