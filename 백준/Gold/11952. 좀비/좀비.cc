#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define ll long long
#define X first
#define Y second
using namespace std;

typedef pair<ll, ll> pi;
typedef tuple<int, int, int> ti;
typedef pair<ll,ll> pl;

const char nl = '\n';
const ll MX = 1e12;
const int MOD = (int)1e9 + 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
  int N, M, K, S;
  cin >> N >> M >> K >> S;
  int P, Q;
  cin >> P >> Q;
  vector<int> zombie(N+1);
  queue<pi> q;
  for(int i = 0; i < K; i ++) {
    int t;
    cin >> t;
    zombie[t] = 2;
    q.push({t, S});
  }
  vector<vector<int>> adj(N+1);
  for(int i = 0; i < M; i ++) {
    int a, b;
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    if(cur.Y <= 0) continue;
    for(auto nxt : adj[cur.X]) {
      if(zombie[nxt]) continue;
      zombie[nxt] = 1;
      q.push({nxt, cur.Y-1});
    }
  }
  vector<ll> dist(N+1, MX);
  priority_queue<pi, vector<pi>, greater<>> pq;
  pq.push({0, 1});
  dist[1] = 0;
  while(!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    
    if(cur.X != dist[cur.Y]) continue;
    for(auto nxt : adj[cur.Y]) {
      ll d;
      if(zombie[nxt]==2)continue;
      else if(zombie[nxt]) d = Q;
      else d = P;
      if(cur.X + d >= dist[nxt]) continue;
      dist[nxt] = cur.X + d;
      pq.push({cur.X + d, nxt});
    }
  }
  if(zombie[N]) cout << dist[N] - Q;
  else cout << dist[N] - P;
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