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
const ll MX = 1e18; 
const int MOD = (int)1e9 + 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void solve() {
  int n, m, w;
  cin >> n >> m >> w;
  vector<pi> adj[n+1];
  for(int i = 0; i < m; i ++) {
    int s, e, t;
    cin >> s >> e >> t;
    s --, e--;
    adj[s].pb({t, e});
    adj[e].pb({t, s});
  }
  for(int i = 0; i < w; i ++) {
    int s, e, t;
    cin >> s >> e >> t;
    s --, e--;
    adj[s].pb({-t, e});
  }
  vector<ll> dist(n, MX);
  dist[0] = 0;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) {
      for(auto [d, nxt] : adj[j]) {
        if(dist[j] + d < dist[nxt]) {
          dist[nxt] = dist[j] + d; 
          if(i == n-1) {
            cout << "YES\n";
            return;
          } 
        } 
      }
    }
  }
  cout << "NO\n";
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