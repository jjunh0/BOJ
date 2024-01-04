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
const int mx = 0x3f3f3f3f;
vector<pair<int, int>> adj[10005];
int d1[1005][1005];
int d2[1005];
void solve() {
  int n, m, x;
  cin >> n >> m >> x;
  while(m--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].pb({c, b});
  }
  for(int i = 1; i <= n; i ++) {
    fill(d1[i], d1[i] + n+1, mx);
    fill(d2, d2 + n+1, mx);
  }
  priority_queue<pi, vector<pi>, greater<pi>> pq;
  for(int i = 1; i <= n; i ++) {
    pq.push({0, i});
    d1[i][i] = 0;
    while(!pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      if(cur.X != d1[i][cur.Y]) continue;
      for(auto nxt : adj[cur.Y]) {
        if(cur.X + nxt.X < d1[i][nxt.Y]) {
          pq.push({cur.X + nxt.X, nxt.Y});
          d1[i][nxt.Y] = cur.X + nxt.X;
        }
      }
    }
  }
  for(int i = 1; i <= n; i ++) {
    pq.push({0, x});
    d2[x] = 0;
    while(!pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      if(cur.X != d2[cur.Y]) continue;
      for(auto nxt : adj[cur.Y]) {
        if(cur.X + nxt.X < d2[nxt.Y]) {
          pq.push({cur.X + nxt.X, nxt.Y});
          d2[nxt.Y] = cur.X + nxt.X;
        }
      }
    }
  }
  int ans = 0;
  for(int i = 1; i <= n; i ++) {
    ans = max(ans, d1[i][x] + d2[i]);
  }
  cout << ans;
}

// ************************************

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++) {
  //#ifdef DEBUG
  //cout << "Case " << i << ":\n";
  //#endif
  solve();
  //#ifdef DEBUG
  //cout << "============\n";
  //#endif
  }
}