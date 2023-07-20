#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define X first
#define Y second

int s[1005][1005];
vector<int> adj[1005];
int ans;
void dfs(int cur, int par, int tar) {
	if(cur == tar) {
		cout << ans << '\n';
		return;
	}
	for(int nxt : adj[cur]) {
		if(nxt == par) continue;
		ans += s[cur][nxt];
		dfs(nxt, cur, tar);
		ans -= s[cur][nxt];
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n-1; i ++) {
		int t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		adj[t1].pb(t2);
		adj[t2].pb(t1);
		s[t1][t2] = t3;
		s[t2][t1] = t3;
	}
	for(int i = 0; i < m; i ++) {
		int t1, t2;
		cin >> t1 >> t2;
		ans = 0;
		dfs(t1, 0, t2);
	}
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}