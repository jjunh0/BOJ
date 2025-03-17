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
  int N, M;
  cin >> N >> M;
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  vector<vector<pi>> adj(N);
  for(int i = 0; i < M; i ++) {
    int a, b, c;
    cin >> a >> b >> c;
    a --, b--;
    adj[a].pb({c, b});
  }
  int A, B; cin >> A >> B;
  A --, B --;
  vector<int> dist(N, MX);
  dist[A] = 0;
  pq.push({0, A});
  while(!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if(dist[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]) {
      if(dist[nxt.Y] > cur.X + nxt.X) {
        dist[nxt.Y] = cur.X + nxt.X;
        pq.push({dist[nxt.Y], nxt.Y});
      }
    }
  }
  cout << dist[B];
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