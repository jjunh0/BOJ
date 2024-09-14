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
  int N, M, S, D;
  while(1) {
    cin >> N >> M;
    if(!N || !M) break;
    cin >> S >> D;
    vector<vector<pi>> adj(N),inv(N);
    for(int i = 0; i < M; i ++) {
      int a, b, c;
      cin >> a >> b >> c;
      adj[a].pb({c, b});
      inv[b].pb({c, a});
    }
    vector<int> dist(N, MX);
    dist[S] = 0;
    priority_queue<pi, vector<pi>, greater<>> pq;
    pq.push({0, S});
    while(!pq.empty()) {
      auto [d, cur] = pq.top();
      pq.pop();
      if(d != dist[cur]) continue;
      for(auto [nd, nxt] : adj[cur]) {
        if(d + nd < dist[nxt]) {
          dist[nxt] = d + nd;
          pq.push({dist[nxt], nxt});
        }
      }
    }
    vector<bool> vis(N);
    set<pi> st;
    queue<int> q;
    vis[D] = 1;
    q.push(D);
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      for(auto nxt : inv[cur]) {
        if(dist[cur] == nxt.X + dist[nxt.Y]) {
          if(!vis[nxt.Y])
            q.push(nxt.Y);
          vis[nxt.Y] = 1;
          st.insert({nxt.Y, cur});
          st.insert({cur, nxt.Y});
        }
      }
    }
    fill(all(dist), MX);
    pq.push({0, S});
    dist[S] = 0;
    while(!pq.empty()) {
      auto [d, cur] = pq.top();
      pq.pop();
      for(auto [nd, nxt] : adj[cur]) {
        if(st.count({cur, nxt})) continue;
        if(dist[nxt] > nd + d) {
          dist[nxt] = nd + d;
          pq.push({dist[nxt], nxt});
        }
      }
    }
    cout << (dist[D] != MX ? dist[D] : -1)<< nl;
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