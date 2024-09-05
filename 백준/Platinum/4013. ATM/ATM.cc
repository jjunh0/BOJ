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
vector<int> adj[500005], inv[500005], val(500005), res(500005), p(500005);
int num = 0, idx = 0;
vector<pi> pn;
vector<bool> vis(500005);
vector<int> scc_res, scc;

void dfs1(int cur) {
  vis[cur] =1;
  for(auto nxt: adj[cur]) {
    if(vis[nxt]) continue;
    dfs1(nxt);
  }
  pn.pb({num, cur});
  num ++;
}
void dfs2(int cur) {
  vis[cur] = 1;
  p[cur] = idx;
  scc[idx] += val[cur];
  if(res[cur]) scc_res[idx] = 1; 
  for(auto nxt : inv[cur]) {
    if(vis[nxt]) continue;
    dfs2(nxt);
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i ++) {
    int a, b; 
    cin >> a >> b;
    a --, b --;
    adj[a].pb(b);
    inv[b].pb(a);
  }
  for(int i = 0; i < n; i ++) {
    int p;
    cin >> p;
    val[i] = p;
  }
  int S, P;
  cin >> S >> P;
  S --;
  for(int i = 0; i < P; i ++) {
    int t;
    cin >> t;
    res[t-1] = 1;
  }  
  for(int i = 0; i < n; i ++) {
    if(vis[i]) continue;
    dfs1(i);
  }
  sort(rall(pn));
  fill(all(vis), 0);
  for(int i = 0; i < n; i ++) {
    auto [num, cur] = pn[i];
    if(vis[cur]) continue;
    scc_res.pb(0);
    scc.pb(0);
    dfs2(cur);
    idx ++;
  }
  vector<int> deg(idx+1), dp(idx+1), scc_adj[idx], s_to_cur(idx);
  for(int i = 0; i < n; i ++) {
    for(auto j : adj[i]) {
      if(p[i] != p[j]) {
        deg[p[j]] ++;
        scc_adj[p[i]].pb(p[j]);
      }
    }
  }
  queue<int> q;
  for(int i = 0; i < idx; i ++) {
    dp[i] = scc[i];
    if(deg[i] == 0) q.push(i);
  }
  int ans = 0;
  s_to_cur[p[S]] = 1;
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(auto nxt : scc_adj[cur]) {
      if(s_to_cur[cur]) {
        dp[nxt] = max(dp[nxt], dp[cur] + scc[nxt]);
        s_to_cur[nxt] = 1;
      }
      deg[nxt] --;
      if(deg[nxt] == 0) q.push(nxt);
    }
  }
  for(int i = 0; i < idx; i ++) {
    if(s_to_cur[i] && scc_res[i]) ans = max(ans, dp[i]);
  }
  cout << ans;
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