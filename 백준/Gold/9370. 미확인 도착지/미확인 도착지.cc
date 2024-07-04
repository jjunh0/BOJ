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

void solve() {
  vector<pair<int, int>> adj[2005];
  int dist[5][2005];
  int n, m, t, s, g, h;
  cin >> n >> m >> t >> s >> g >> h;
  while(m--) {
    int a, b, d;
    cin >> a >> b >> d;
    adj[a].pb({d, b});
    adj[b].pb({d, a});
  }
  for(int i = 0; i < 5; i ++) fill(dist[i], dist[i]+2005, MX);
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  vector<int> v = {s, g, h};
  for(int i = 0 ; i < 3; i ++) {
    pq.push({0, v[i]});
    dist[i][v[i]] = 0;
    while(!pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      for(auto nxt : adj[cur.Y]) {
        if(dist[i][nxt.Y] <= cur.X + nxt.X) continue;
        dist[i][nxt.Y] = cur.X + nxt.X;
        pq.push({cur.X + nxt.X, nxt.Y});
      }
    }
  }
  vector<int> ans;
  while(t--) {
    int cand;
    cin >> cand;
    if(dist[0][g] + dist[1][h] + dist[2][cand] == dist[0][cand] || 
      dist[0][h] + dist[2][g] + dist[1][cand] == dist[0][cand]) ans.pb(cand); 
  }
  sort(all(ans));
  for(auto e: ans) cout << e << ' ';
  cout << nl;
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
}
