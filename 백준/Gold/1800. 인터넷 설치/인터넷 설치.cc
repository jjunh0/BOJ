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


void solve() {
  int N, P, K;
  cin >> N >> P >> K;
  vector<vector<pi>> adj(N);
  for(int i = 0; i < P; i ++) {
    int a, b, c;
    cin >> a >> b >> c;
    a --, b --;
    adj[a].pb({c, b});
    adj[b].pb({c, a});
  }
  int st = -1, en = 1000000;
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  vector<int> dist(N, MX);
  while(st + 1 < en) {
    int mid = (st+en)/2;
    fill(all(dist), MX);
    dist[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()) {
      auto [d, cur] = pq.top();
      pq.pop();
      if(d != dist[cur]) continue;
      for(auto [nd, nxt] : adj[cur]) {
        if(d + (nd > mid) < dist[nxt]) {
          dist[nxt] = d + (nd > mid);
          pq.push({dist[nxt], nxt});
        }
      }
    }
    if(dist[N-1] == MX) {
      cout << -1;
      return;
    }
    if(dist[N-1] > K) st = mid;
    else en = mid;
  } 
  cout << (dist[N-1] < K ? 0 : en);
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