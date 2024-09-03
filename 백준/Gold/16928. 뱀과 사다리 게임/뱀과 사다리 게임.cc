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
  int n, m;
  cin >> n >> m;
  vector<int> nxt(100), vis(100);
  iota(all(nxt), 0);
  for(int i = 0; i < n+m; i ++) {
    int x, y;
    cin >> x >> y;
    x --, y --;
    nxt[x] = y;
  }
  queue<int> q;
  q.push(0);
  while(!q.empty()) {
    int cur = q.front();
    q.pop();
    for(int i = 1; i <= 6; i ++) {
      int nx = cur + i;
      nx = nxt[nx];
      if(vis[nx] || nx >= 100) continue;
      vis[nx] = vis[cur] + 1;
      q.push(nx);
    }
  }
  cout << vis[99];
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