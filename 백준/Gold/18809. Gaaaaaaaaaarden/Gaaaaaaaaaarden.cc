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
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int board[55][55], vis[55][55], f[55][55];
int n, m, G, R, cnt;

void bfs(queue<pi> &q) {
  while(sz(q)) {
    auto cur = q.front();
    q.pop();
    if(f[cur.X][cur.Y] == 1) continue;
    for(int dir = 0; dir < 4; dir ++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny] == 0 || f[nx][ny]) continue;
      int val = 1;
      if(vis[cur.X][cur.Y] > 0) val = -1;
      if(vis[nx][ny] == -vis[cur.X][cur.Y] + val) {
        cnt ++;
        f[nx][ny] = 1;
        continue;
      }
      if(vis[nx][ny] != 0) continue;
      q.push({nx, ny});
      vis[nx][ny] = vis[cur.X][cur.Y] - val;

    }
  }
}


void solve() {
  cin >> n >> m >> G >> R;
  vector<pi> cand;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) { 
      cin >> board[i][j];
      if(board[i][j] == 2) cand.pb({i, j});
    } 
  }
  int ans = 0;
  vector<int> idx;
  for(int i = 0; i < sz(cand); i ++) {
    if(i < G) idx.pb(0);
    else if(i < R+G) idx.pb(1);
    else idx.pb(2);
  }
  do {
    for(int i = 0; i < n; i ++) {
      fill(vis[i], vis[i]+m, 0);
      fill(f[i], f[i]+m, 0);
    }
    queue<pi> q;
    for(int i = 0; i < sz(idx); i ++) {
      if(idx[i] == 0) {
        vis[cand[i].X][cand[i].Y] = 1;
        q.push({cand[i].X, cand[i].Y});
      }
      else if(idx[i] == 1){
        vis[cand[i].X][cand[i].Y] = -1;
        q.push({cand[i].X, cand[i].Y});
      }
    }
    cnt = 0;
    bfs(q);
    ans = max(ans, cnt);

  } while(next_permutation(all(idx)));
  cout << ans;
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