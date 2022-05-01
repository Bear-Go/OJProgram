#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
pair<int, int> points[100010];

vector<pair<int, ll>> adj[100010];

void add(int u, int v) {
    ll dx = points[u].first - points[v].first;
    ll dy = points[u].second - points[v].second;
    ll w = dx * dx + dy * dy;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

ll prims() {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<bool> visited(N, false);
    pq.push({0, 0});
    ll ans = 0;
    while (!pq.empty()) {
        auto t = pq.top(); pq.pop();
        if (visited[t.second]) continue;
        visited[t.second] = true;
        ans += t.first;
        for (auto p : adj[t.second]) {
            pq.push({p.second, p.first});
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) 
        cin >> points[i].first >> points[i].second;

    sort(points, points + N);
    vector<int> last(11, -1);
    for (int i = 0; i < N; i++) {
        if (i < N - 1) add(i, i + 1);
        for (int y = 0; y <= 10; y++) {
            if (last[y] != -1) add(i, last[y]);
        }
        last[points[i].second] = i;
    }

    cout << prims() << endl;

    return 0;
}