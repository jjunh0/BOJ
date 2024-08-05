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
typedef tuple<int, int, int> ti;
const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int vis[15][15], board[15][15], dist[10][10], chk[10];
void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < 10; i ++) {
    fill(dist[i], dist[i]+10, MX);
    for(int j = 0; j < m; j ++) {
      cin >> board[i][j];
    }
  }
  int cur_i = 1;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) {
      if(vis[i][j] || board[i][j] == 0) continue;
      queue<pi> q;
      q.push({i, j});
      vis[i][j] = cur_i;
      while(sz(q)) {
        auto cur = q.front();
        q.pop();
        for(int dir = 0; dir < 4; dir ++) {
          int nx = dx[dir] + cur.X;
          int ny = dy[dir] + cur.Y;
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if(vis[nx][ny] || board[nx][ny] == 0) continue;
          vis[nx][ny] = cur_i;
          q.push({nx, ny});
        }
      }
      cur_i ++;
    }
  }
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) {
      if(board[i][j] == 0 || vis[i][j] == 0) continue;
      for(int dir = 0; dir < 4; dir ++) {
        int nx = i;
        int ny = j;
        int cnt = 0;
        while(1) {
          nx += dx[dir];
          ny += dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= m) break;
          if(vis[nx][ny] == vis[i][j]) break;
          if(vis[nx][ny] != 0 && vis[nx][ny] != vis[i][j]) {
            if(cnt >= 2) dist[vis[nx][ny]][vis[i][j]] = min(dist[vis[nx][ny]][vis[i][j]], cnt);
            break;
          }
          cnt ++;
        }
      }
    }
  }
  for(int i = 1; i < cur_i; i ++) dist[i][i] = 0;
  priority_queue<ti, vector<ti>, greater<ti>> pq;
  int cnt = 0;
  chk[1] = 1;
  for(int i = 1; i < cur_i; i ++){
    if(dist[1][i] == MX || dist[1][i] <= 1) continue;
    pq.push({dist[1][i], 1, i});
  }

  int ans = 0;
  while(sz(pq) && cnt < cur_i-2) {
    int cost, a, b;
    tie(cost, a, b) = pq.top();
    pq.pop();
    if(chk[b]) continue;
    chk[b] = 1;
    ans += cost;
    cnt ++;
    for(int i = 1; i < cur_i; i ++) {
      if(dist[b][i] == MX || dist[b][i] <= 1) continue;
      if(!chk[i]) {
        pq.push({dist[b][i], b, i});
      }
    }
  }
  cout << (cnt == cur_i-2 ? ans : -1) << nl;
}

// ************************************

int main() {
    // ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--) {
        solve();
    }
}