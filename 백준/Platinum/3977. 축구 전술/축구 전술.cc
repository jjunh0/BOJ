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
vector<vector<int>> adj, inv, scc;
vector<int> vis, p;
vector<pi> pn;
int idx, num;
void dfs1(int cur) {
  vis[cur] = 1;
  for (auto e : adj[cur]) {
    if(vis[e]) continue;
    dfs1(e);
  }
  pn.pb({num++, cur});
}

void dfs2(int cur) {
  vis[cur] = 1;
  p[cur] = idx;
  scc[idx].pb(cur);
  for(auto nxt : inv[cur]) {
    if(vis[nxt]) continue;
    dfs2(nxt);
  }
}
void solve() {
  int N, M;
  cin >> N >> M;
  adj.assign(N+1, {});
  inv.assign(N+1, {});
  scc.assign(N+1, {});
  vis.assign(N+1, 0);
  p.assign(N+1, 0);
  pn.clear();
  num = 0, idx = 0;
  for(int i = 0; i < M; i ++) {
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    inv[b].pb(a);
  }
  for(int i = 0; i < N; i ++) {
    if(vis[i]) continue;
    dfs1(i);
  }
  sort(rall(pn));
  fill(all(vis), 0);
  for(int i = 0; i < N; i ++) {
    auto [num, cur] = pn[i];
    if(vis[cur]) continue;
    dfs2(cur);
    idx ++;
  }
  vector<int> deg(idx);
  for(int i = 0; i < N; i ++) {
    for(auto nxt : adj[i]) {
      if(p[i] != p[nxt]) {
        deg[p[nxt]] ++;
      }
    }
  }
  vector<int> ans;
  int cnt = 0;
  for(int i = 0; i < idx; i ++) {
    if(deg[i] == 0) {
      for(auto e : scc[i]) ans.pb(e);
      cnt ++;
    }
  }
  sort(all(ans));
  if(cnt != 1) cout << "Confused\n"; 
  else for(auto e : ans) cout << e << nl;
  cout << nl;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    while(tests--) {
        solve();
    }
}