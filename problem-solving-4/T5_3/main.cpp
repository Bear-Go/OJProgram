#include<bits/stdc++.h> 

using namespace std;

int n, a[2000005];
long long f[2000005][25];

int main()
{
    ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		f[a[i]][0]++;
	}
    
	int bound = (1 << 20) - 1;
	for (int i = 0; i <= bound; ++i)
	{
		for (int k = 0; k <= 19; ++k)
		{
			if (!f[i][k]) continue;
			if (k != 0) 
			{	
				f[i][k] /= k;
				f[i][0] += f[i][k];
			}
			for (int j = 0; j <= 19; ++j)
				if (!((1<<j)&i))
                    f[i|(1<<j)][k+1]+=f[i][k];
		}
		f[i][20] /= 20;
		f[i][0] += f[i][20];
	}
	long long sum = 0;
	for (int i = 1; i <= n; ++i) sum += f[bound^a[i]][0];
	cout << sum << endl;
}