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
  vector<vector<pi>> adj(N), inv(N);
  for(int i = 0; i < M; i ++) {
    int a, b, c;
    cin >> a >> b >> c;
    a --, b --;
    adj[a].pb({c, b});
    inv[b].pb({c, a});
  }
  int st, en;
  cin >> st >> en;
  st --, en --;
  vector<int> deg(N);
  for(int i = 0; i < N; i ++) {
    for(auto nxt : adj[i]) deg[nxt.Y] ++;
  }
  queue<int> q;
  vector<int> val(N);
  for(int i = 0; i < N; i ++) {
    if(deg[i] == 0) {
      q.push(i);
    }
  }
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(auto nxt : adj[cur]) {
      deg[nxt.Y] --;
      if(deg[nxt.Y] == 0) q.push(nxt.Y);
      if(val[nxt.Y] <= val[cur] + nxt.X) {
        val[nxt.Y] = val[cur] + nxt.X;
      }
    }
  }
  int cnt = 0;
  q.push(en);
  set<pi> vis;
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(auto nxt : inv[cur]) {
      if(val[cur] == val[nxt.Y]+ nxt.X && !vis.count({cur, nxt.Y})) {
        cnt ++;
        q.push(nxt.Y);
        vis.insert({cur, nxt.Y});
      }
    }
  }
  cout << val[en] << nl << cnt;
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