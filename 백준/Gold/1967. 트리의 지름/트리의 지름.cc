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
vector<pi> adj[10005];
int nxt[10005];
int mx = 0, v1;
int dfs(int cur, int p) {
  int dist = 0;
  for(auto e : adj[cur]) {
    if(e.Y == p) continue;
    int t = e.X + dfs(e.Y, cur);
    if(dist < t) {
      nxt[cur] = e.Y;
      dist = t;
    }
  }
  return dist;
}

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n-1; i ++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].pb({c, b});
    adj[b].pb({c, a});
  }
  fill(nxt, nxt+n+1, -1);
  dfs(1, -1);
  int v = 1;
  while(nxt[v] != -1) v = nxt[v];
  cout << dfs(v, -1);
  
}

// ************************************

int main() {
    // ios::sync_with_stdio(0);
    cin.tie(0);
    int tests = 1;
    while(tests--) {
        solve();
    }
}