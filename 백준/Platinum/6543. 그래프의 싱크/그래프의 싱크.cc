#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define ll long long
#define X first
#define Y second
using namespace std;

typedef pair<int, int> pi;
typedef tuple<int, int, int> ti;
typedef pair<ll,ll> pl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = (int)1e9 + 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int idx, num;

void dfs1(int cur, vector<int> &vis, vector<int> *adj, vector<pi> &pn) {
  vis[cur] = 1;
  for(auto nxt : adj[cur]) {
    if(vis[nxt]) continue;
    dfs1(nxt, vis, adj, pn);
  }
  pn.pb({num++, cur});
}

void dfs2(int cur, vector<int> &vis, vector<int> *inv, vector<int> &p, vector<int> *scc) {
  vis[cur] = 1;
  p[cur] = idx;
  scc[idx].pb(cur);
  for(auto nxt : inv[cur]) {
    if(vis[nxt]) continue;
    dfs2(nxt, vis, inv, p, scc);
  }
}

void solve() {
  int n, m;
  while(cin >> n, n) {
    cin >> m;
    vector<int> adj[n], inv[n], scc[n];
    for(int i = 0; i < m; i ++) {
      int a, b;
      cin >> a >> b;
      a --, b--;
      adj[a].pb(b);
      inv[b].pb(a);
    }
    num = 0;
    vector<int> vis(n);
    vector<pi> pn;
    for(int i = 0; i < n; i ++) {
      if(vis[i]) continue;
      dfs1(i, vis, adj, pn);
    }
    fill(all(vis), 0);
    sort(rall(pn));
    vector<int> p(n);
    idx = 0;
    for(int i = 0; i < n; i ++) {
      auto [num, cur] = pn[i];
      if(vis[cur]) continue;
      dfs2(cur, vis, inv, p, scc);
      idx ++;
    }
    vector<int> deg(idx);
    for(int i = 0; i < n; i ++) {
      for(auto nxt : adj[i]) {
        if(p[i] == p[nxt]) continue;
        deg[p[i]] ++;
      }
    }
    vector<int> ans;
    for(int i = 0; i < idx; i ++) {
      if(deg[i] == 0) {
        for(auto e : scc[i]) ans.pb(e);
      }
    }
    sort(all(ans));
    for(auto e : ans) cout << e+1 << ' ';
    cout << nl;
  }
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    while(tests--) {
        solve();
    }
}