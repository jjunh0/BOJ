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

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dist[105][105];
int p[105];
int find(int x) {
  if(p[x] == -1) return x;
  return p[x] = find(p[x]);
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if(a == b) return;
  if(p[a] < p[b]) p[b] = a;
  else p[a] = b;
}

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) fill(dist[i]+1, dist[i]+1+n, MX);
  fill(p, p+n+1, -1);
  while(m--) {
    int a, b;
    cin >> a >> b;
    merge(a, b);
    dist[a][b] = 1;
    dist[b][a] = 1;
  }
  for(int i = 1; i <= n; i ++) dist[i][i] = 0;
  for(int t = 1; t <= n; t ++) {
    for(int i = 1; i <= n; i ++) {
      for(int j = 1; j <= n; j ++) { 
        dist[i][j] = min(dist[i][j], dist[i][t] + dist[t][j]);
      } 
    }
  }
  vector<int> adj[n+1];
  for(int i = 1; i <= n; i ++) {
    adj[find(i)].pb(i);
  }
  vector<int> ans;
  for(int k = 0; k <= n; k ++) {
    if(!sz(adj[k])) continue;
    int t_mn = 0x3f3f3f3f, t_idx = 0;;
    for(int i = 0; i < sz(adj[k]); i ++) {
      int mx = 0, mx_idx;
      for(int j = 0; j < sz(adj[k]); j ++) {
        mx = max(mx, dist[adj[k][i]][adj[k][j]]);
      }
      if(t_mn > mx) {
        t_mn = mx;
        t_idx = adj[k][i];
      }
    }
    ans.pb(t_idx);
  }
  sort(all(ans));
  cout << sz(ans) << nl;
  for(auto e : ans) cout << e << nl;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        solve();
    }
}