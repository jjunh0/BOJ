#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define ll long long
#define X first
#define Y second
#define int ll
using namespace std;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
const int mx = 0x3f3f3f3f;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<pi> adj[5005];
int d[2][5005];
int V, E, P;
void dij(int C, int st) {
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  pq.push({0, st});
  d[C][st] = 0;

  while(!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if(d[C][cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]) {
      if(d[C][nxt.Y] <= cur.X + nxt.X) continue;
      d[C][nxt.Y] = cur.X + nxt.X;
      pq.push({d[C][nxt.Y], nxt.Y});
    }
  }
}

void solve() {
  cin >> V >> E >> P;
  for(int i = 0; i < E; i ++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].pb({c, b});
    adj[b].pb({c, a});
  }
  for(int i = 0; i < 2; i ++) fill(d[i], d[i]+5005, mx);
  dij(0, 1);
  dij(1, P);
  if(d[0][V] == d[0][P] + d[1][V]) cout << "SAVE HIM";
  else cout << "GOOD BYE";

}

// ************************************

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt = 1;
  while(tt--) {
    solve();
  }
}