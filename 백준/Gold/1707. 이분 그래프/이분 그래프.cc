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
vector<vector<int>> adj;
vector<int> vis;

void dfs(int cur, int val) {
  vis[cur] = val;
  for(auto nxt : adj[cur]) {
    if(vis[nxt] != -1) continue;
    dfs(nxt, !val);
  }
}

void solve() {
  int V, E;
  cin >> V >> E;
  adj.assign(V, {});
  vis.assign(V, -1);
  for(int i = 0; i < E; i ++) {
    int a, b;
    cin >> a >> b;
    a --, b --;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  for(int i = 0; i < V; i ++) {
    if(vis[i] != -1) continue;
    dfs(i, 0);
  }
  for(int i = 0; i < V; i ++) {
    for(auto e : adj[i]) {
      if(vis[e] == vis[i]) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
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