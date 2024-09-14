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
const ll MX = (ll)1e18;
const int MOD = (int)1e9 + 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
  ll N, M;
  cin >> N >> M;
  vector<vector<pi>> adj(N);
  for(int i = 0; i < M; i ++) {
    int a, b;
    cin >> a >> b;
    a --, b --;
    adj[a].pb({i, b});
    adj[b].pb({i, a});
  }
  vector<ll> dist(N, MX);
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  pq.push({0, 0});
  dist[0] = 0;
  while(!pq.empty()) {
    auto [d, cur] = pq.top();
    pq.pop();
    if(d != dist[cur]) continue;
    if(cur == N-1) {
      cout << d; return;
    }
    for(auto [nd, nxt] : adj[cur]) {
      if(nd < d) {
        ll t  =(d - nd)/M + ((d-nd)%M != 0);
        nd = nd + t*M;
      }
        
      if(nd+1 < dist[nxt]) {
        dist[nxt] = nd+1;
        pq.push({nd+1, nxt});
      }
    }
  }
  cout << dist[N-1];
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