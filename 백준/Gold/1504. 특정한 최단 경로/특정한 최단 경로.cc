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
const int mx = 0x3f3f3f3f;

vector<pi> adj[805];

ll dijkstra(int a, int b) {
  vector<int> d(805, mx);
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  pq.push({0, a});
  d[a] = 0;
  while(!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if(cur.X != d[cur.Y]) continue;
    for(auto nxt : adj[cur.Y]) {
      if(cur.X + nxt.X < d[nxt.Y]) {
        pq.push({cur.X+nxt.X, nxt.Y});
        d[nxt.Y] = cur.X + nxt.X;
      } 
    }
  }
  return d[b];

}

void solve() {
  int n, e;
  cin >> n >> e;

  for(int i = 0; i < e; i ++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].pb({c, b});
    adj[b].pb({c, a});
  }
  int v1, v2;
  cin >> v1 >> v2;
  ll a = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, n);
  ll b = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, n);
  if(a >= mx) cout << -1;
  else cout << min(a, b); 
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
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