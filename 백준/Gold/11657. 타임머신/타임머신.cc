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

vector<pi> adj[505];
void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < m; i ++) {
    int a, b, c;
    cin >> a >> b >> c;
    a --; b --;
    adj[a].pb({c, b});
  }
  vector<ll> dist(n, MX);
  dist[0] = 0;
  bool flag = false;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) {
      for(auto nxt : adj[j]) {
        if(dist[j] == MX || dist[nxt.Y] <= dist[j] + nxt.X) continue;
        dist[nxt.Y] = dist[j] + nxt.X;
        if(i == n-1) flag = true;
      }
    }
  } 
  if(flag) {
    cout << -1;
    return;
  }
  for(int i = 1; i < n; i ++) {
    cout << (dist[i]==MX ? -1 : dist[i]) << nl;
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