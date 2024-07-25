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
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef tuple<int, int, int> ti;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<pi> adj[3][4005];
void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i ++) {
    int a, b, d;
    cin >> a >> b >> d;
    adj[0][a].pb({d, b});
    adj[0][b].pb({d, a});
    adj[2][a].pb({d*2, b});
    adj[2][b].pb({d*2, a});
    adj[1][a].pb({d*4, b});
    adj[1][b].pb({d*4, a});
  }
  // fox
  vector<int> f_vis(n+1, MX);
  priority_queue<pi, vector<pi>, greater<pi>> pq_f;
  f_vis[1] = 0;
  pq_f.push({f_vis[1], 1});
  while(sz(pq_f)) {
    auto cur = pq_f.top();
    pq_f.pop();
    if(f_vis[cur.Y] != cur.X) continue;
    for(auto nxt : adj[2][cur.Y]) {
      if(f_vis[nxt.Y] <= cur.X + nxt.X) continue;
      f_vis[nxt.Y] = cur.X + nxt.X;
      pq_f.push({f_vis[nxt.Y], nxt.Y});
    }
  }
  priority_queue<ti, vector<ti>, greater<ti>> pq_w;
  int w_vis[2][n+1];
  for(int i = 0; i < 2; i ++) fill(w_vis[i], w_vis[i]+n+1, MX);
  pq_w.push({0, 1, 0});
  while(sz(pq_w)) {
    auto [dis, cur, flag] = pq_w.top();
    pq_w.pop();
    for(auto nxt : adj[flag][cur]) {
      if(w_vis[flag][nxt.Y] <= dis + nxt.X) continue;
      w_vis[flag][nxt.Y] = nxt.X + dis;
      pq_w.push({w_vis[flag][nxt.Y], nxt.Y, !flag});
    }
  }
  int ans = 0;
  for(int i = 2; i <= n; i ++) {
    if(f_vis[i] < min(w_vis[0][i],w_vis[1][i])) ans ++;
  }
  cout << ans;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
        solve();
    }
}