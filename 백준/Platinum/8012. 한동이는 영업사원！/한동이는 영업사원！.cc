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

vector<int> adj[30005];
vector<int> depth(30005, -1);
int parent[30005][20];

void dfs(int cur) {
  for(auto e : adj[cur]) {
    if(depth[e] != -1) continue;
    depth[e] = depth[cur] + 1;
    parent[e][0] = cur;
    dfs(e);
  }
}

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n-1; i ++) {
    int x, y;
    cin >> x >> y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  memset(parent, -1, sizeof(parent));
  depth[1] = 0;
  dfs(1);

  for(int j = 0; j < 16; j ++) {
    for(int i = 1; i <= n; i ++) {
      if(parent[i][j] != -1)
        parent[i][j+1] = parent[parent[i][j]][j];
    }
  }
  
  int m;
  cin >> m;
  int cur = 1, ans = 0;
  while(m --) {
    int nxt;
    cin >> nxt;
    int x = cur, y = nxt;
    if(depth[x] > depth[y]) swap(x, y);
    // y가 아래
    int xx = x, yy = y;
    int diff = depth[y] - depth[x];
    for(int j = 0; diff; j ++) {
      if(diff & 1) {
        y = parent[y][j];
      }
      diff = (diff >> 1);
    }
    if(x == y) {
      ans += depth[yy] - depth[xx];
    }
    else {
      for(int j = 15; j >= 0; j --) {
        if(parent[x][j] != -1 && parent[x][j] != parent[y][j]) {
          x = parent[x][j];
          y = parent[y][j];
        }
      }
      x = parent[x][0];
      ans += depth[yy] + depth[xx] - 2*depth[x];
    }
    cur = nxt;
  }
  cout << ans << nl;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) {
  //#ifdef DEBUG
  //cout << "Case " << i << ":\n";
  //#endif
  solve();
  //#ifdef DEBUG
  //cout << "============\n";
  //#endif
  }
}