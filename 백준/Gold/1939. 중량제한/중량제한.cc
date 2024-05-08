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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<pi> adj[10005];
int N, M;

bool dfs(int mid, int x, int y) {
  vector<int> vis(100005, 0);
  queue<int> q;
  q.push(x);
  vis[x] = 1;
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    if(cur == y) return true;
    for(auto nxt : adj[cur]) {
      if(vis[nxt.Y] || nxt.X < mid) continue;
      q.push(nxt.Y);
      vis[nxt.Y] = 1;
    }
  }
  return false;
}

void solve() {
  cin >> N >> M;
  int mx = 0;
  for(int i = 0; i < M; i ++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].pb({c, b});
    adj[b].pb({c, a});
    mx = max(c, mx);
  }
  int x, y;
  cin >> x >> y;
  int st=0, en = mx+1;
  while(st+1 < en) {
    int mid = (st+en)/2;
    if(dfs(mid, x, y)) st = mid;
    else en = mid;
  }
  cout << st;
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