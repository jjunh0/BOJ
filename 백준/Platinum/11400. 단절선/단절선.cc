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
const int MAX = 100005;
vector<vector<int>> adj;
int dsfn[MAX], cnt = 1;
vector<int> AP(MAX);
vector<pi> ans;
int dfs(int cur, int p) {
  int res = dsfn[cur] = cnt ++;
  for(auto nxt : adj[cur]) {
    if(nxt == p) continue;
    if(dsfn[nxt] == 0) {
      int temp = dfs(nxt, cur);
      res = min(temp, res);
      if(temp > dsfn[cur]) ans.pb({min(cur, nxt), max(cur, nxt)});
    }
    else { // 역방향
      res = min(res, dsfn[nxt]);
    }
  }
  return res;
}

void solve() {
  int V, E;
  cin >> V >> E;
  adj.assign(V+1, {});
  for(int i = 0; i < E; i ++) {
    int a, b;
    cin >> a >> b;
    a --, b --;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  for(int i = 0; i < V;i ++) {
    if(dsfn[i] == 0) dfs(i, -1);
  }
  sort(all(ans));
  cout << sz(ans) << nl;
  for(auto e : ans) {
    cout << e.X+1 << ' ' << e.Y+1 << nl;
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