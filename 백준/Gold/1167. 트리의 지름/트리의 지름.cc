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

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
vector<pi> adj[100005];
vector<int> dist(100005); // 정점 i 부터 leaf node 까지의 거리 중 최대값
vector<int> a(100005, -1);
int func(int cur, int p) {
  for(auto nxt : adj[cur]) {
    if(nxt.X == p) continue;
    int tmp = func(nxt.X, cur) + nxt.Y;
    if(dist[cur] < tmp) {
      dist[cur] = tmp;
      a[cur] = nxt.X;
    }
  }
  return dist[cur];
}

void solve() {
  int v;
  cin >> v;
  for(int i = 1; i <= v; i ++) {
    int cur;
    cin >> cur;
    int t;
    while(cin >> t, t != -1) {
      int b;
      cin >> b;
      adj[cur].pb({t, b});
    }
  }
  func(1, -1);
  int cur = 1;
  while(a[cur] != -1) cur = a[cur];
  fill(all(dist), 0);
  cout << func(cur, -1);
}

// ************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
        solve();
    }
}