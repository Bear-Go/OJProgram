#include <bits/stdc++.h>

using namespace std;

int cost[205][205];
map<pair<int, int>, int> mp;
set<int> T;
int n, m, c;

int main() 
{
	cin >> n >> m;
	int f = n;
	for (int i = 1; i <= m; ++i) 
    {
        int x, y, z;
		cin >> x >> y >> z;
        pair<int, int> p;
		if (z < 0) 
        {
			cost[x][y] = abs(z);
			cost[y][x] = abs(z);
			c += abs(z);
			p = make_pair(x, y);
			mp[p] = i;			
		}
		else 
        {
			f++;
			cost[x][f] = z; cost[y][f] = z; cost[f][x] = z; cost[f][y] = z;
			p = make_pair(x, f); mp[p] = i;
			p = make_pair(y, f); mp[p] = i;
		}
	}
	for (int i = 1; i <= f; ++i) T.insert(i);

	set<int> S;
	S.insert(1);
	T.erase(1);
    int max_cost = 0;
	for (auto v : T) max_cost += cost[1][v];
	int cur_cost = max_cost;
	
	while(1) {
		bool flag = false;
		for (auto t : T) 
        {
			cur_cost = max_cost;
			for (auto x : S) cur_cost -= cost[x][t];
			for (auto x : T) if (x != t) cur_cost += cost[x][t];
			if (cur_cost > max_cost) 
            {
				max_cost = cur_cost;
				flag = true;
				T.erase(t);
				S.insert(t);
				break;
			}
		}
		if (!flag) break;
	}

	int ans = c - max_cost;
	vector<int> buf;
	for (auto i : S)
		for (auto j : S) 
        {
			pair<int, int> p = make_pair(i, j);
			auto got = mp.find(p);
			if (got != mp.end()) buf.push_back(got->second);
		}
	for (auto i : T)
		for (auto j : T) 
        {
			pair<int, int> p = make_pair(i, j);
			auto got = mp.find(p);
			if (got!= mp.end()) buf.push_back(got->second);
		}
    cout << buf.size() << endl;
    for (auto i : buf) cout << i << " ";
    return 0;
}