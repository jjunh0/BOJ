#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define X first
#define Y second

vector<int> adj[100005];
int par[100005];
int cnt[100005];

void cntNodes(int cur) {
	cnt[cur] = 1;
	for(int nxt : adj[cur]) {
		if(nxt == par[cur]) continue;
		par[nxt] = cur;
		cntNodes(nxt);
		cnt[cur] += cnt[nxt];
	}
}

void solve() {
	int n, r, q;
	cin >> n >> r >> q;
	for(int i = 0; i < n-1; i ++) {
		int t1, t2;
		cin >> t1 >> t2;
		adj[t1].pb(t2);
		adj[t2].pb(t1);
	}
	//dfs(r);
	cntNodes(r);
	for(int i = 0; i < q; i ++) {
		int tmp;
		cin >> tmp;
		cout << cnt[tmp] << '\n';
	}
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}