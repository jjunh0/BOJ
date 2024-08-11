#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define X first
#define Y second

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> d(n+1);
	for(int i = 1; i <= n; i ++) {
		cin >> d[i];
	}
	
	vector<int> adj[n+1];
	vector<int> ind(n+1);
	vector<int> dp(n+1);
	for(int i = 0; i < k; i ++) {
		int x, y;
		cin >> x >> y;
		adj[x].pb(y);
		ind[y] ++;
	}

	int w;
	cin >> w;
	queue<int> q;
	for(int i = 1; i <= n; i ++) {
		if(ind[i] == 0) {
			q.push(i);
			dp[i] = d[i];
		}
		
	}
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for(int nxt : adj[cur]) {
			if(--ind[nxt] == 0) q.push(nxt);
			dp[nxt] = max(dp[nxt], dp[cur] + d[nxt]);
		}
	}

	
	cout << dp[w] << '\n';
	
}

// ************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--)
		solve();
}