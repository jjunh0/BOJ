#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define X first
#define Y second

vector<int> adj[100005];
bool vis[100005];
void solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i ++) {
		int t1, t2;
		cin >> t1 >> t2;
		adj[t1].pb(t2);
		adj[t2].pb(t1);
	}
	int ans = 0;
	for(int i = 1; i <= n; i ++) {
		if(vis[i]) continue;
		ans ++;
		queue<int> q;
		q.push(i);
		vis[i] = 1;	
		int cnt = 0;
		int connect = 0;
		while(!q.empty()) {
			int cur = q.front();
			q.pop();
			cnt ++;
			connect += adj[cur].size()
;			for(int nxt : adj[cur]) {
				if(vis[nxt]) continue;
				q.push(nxt);
				vis[nxt] = 1;
			}
		}
		ans += connect/2 - (cnt - 1);
		//cout << i << ' ' << connect /2 -  (cnt - 1) << '\n';
	}
	cout << ans - 1 <<'\n';
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}