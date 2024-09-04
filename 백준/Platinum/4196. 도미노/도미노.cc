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
int num = 1, idx = 1;
void dfs1(int cur, vector<bool> &vis, vector<int> (&adj)[100005], vector<pi> &pn) {
  for(auto nxt : adj[cur]) {
    if(vis[nxt]) continue;
    vis[nxt] = 1;
    dfs1(nxt, vis, adj, pn);
  }
  pn.pb({num, cur});
  num ++;
}
void dfs2(int cur, vector<bool> &vis, vector<int> (&inv)[100005], vector<int> &p) {
  for(auto nxt : inv[cur]) {
    if(vis[nxt]) continue;
    vis[nxt] = 1;
    p[nxt] = idx;
    dfs2(nxt, vis, inv, p);
  }
}

void solve() {
  num = 1, idx = 1;
  int n, m;
  cin >> n >> m;
  vector<int> adj[100005], inv[100005];
  vector<bool> vis(n+5);
  vector<int> deg(n+5), p(n+5);
  vector<pi> pn;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a --, b --;
    adj[a].pb(b);
    inv[b].pb(a);
  }
  for(int i = 0; i < n; i ++) {
    if(vis[i]) continue;
    vis[i] = 1;
    dfs1(i, vis, adj, pn);
  }
  sort(rall(pn));
  fill(all(vis), 0);
  for(int i = 0; i < sz(pn); i ++) {
    if(vis[pn[i].Y]) continue;
    vis[pn[i].Y] =1;
    p[pn[i].Y] = idx;
    dfs2(pn[i].Y, vis, inv, p);
    idx ++;
  }
  for(int i = 0; i < n; i ++) {
    for(auto nxt : adj[i]) {
      if(p[i] != p[nxt]) deg[p[nxt]] ++;
    }
  }
  int cnt= 0;
  for(int i = 1; i < idx; i ++) {
    if(deg[i] == 0) cnt ++;
  }
  cout << cnt << nl;
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