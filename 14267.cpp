#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define X first
#define Y second
#define MN 100005

int p[MN];
vector<int> adj [MN];
int dp[MN];
void dfs(int cur) {
	for(int nxt : adj[cur]) {
		if(nxt == p[cur]) continue;
		dp[nxt] += dp[cur];
		dfs(nxt);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		int tmp;
		cin >> tmp;
		if(tmp == -1) continue;
		adj[i].pb(tmp);
		adj[tmp].pb(i);
		p[i] = tmp;
	}

	while(m--) {
		int cur, pen;
		cin >> cur >> pen;
		dp[cur] += pen;
	}

	dfs(1);

	for(int i = 1; i <= n; i++) cout << dp[i] << ' ';
}

// ************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}