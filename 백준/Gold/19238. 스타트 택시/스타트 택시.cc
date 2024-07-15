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

int n, m, f, cur_x, cur_y, cnt = 1, cur_cnt;

void solve() {
  vector<vector<int>> p(25, vector<int>(25));
  pi d[405];
  cin >> n >> m >> f;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < n; j ++) {
      cin >> p[i][j];
      if(p[i][j]) p[i][j] = -1;
    }
  }
  cin >> cur_x >> cur_y;
  cur_x --; cur_y --;
  for(int i = 0; i < m; i ++) {
    int x, y, dx, dy;
    cin >> x >> y >> dx >> dy;
    x --; y --; dx --; dy --;
    p[x][y] = cnt;
    d[cnt] = {dx, dy};
    cnt ++;
  }
  for(int i = 0; i < m; i ++) {
    vector<vector<int>> vis(25, vector<int>(25, 0));
    queue<pi> q;
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    q.push({cur_x, cur_y});
    vis[cur_x][cur_y] = 1;
    while(sz(q)) {
      auto cur = q.front();
      q.pop();
      if(p[cur.X][cur.Y] > 0) pq.push({vis[cur.X][cur.Y]-1, cur.X, cur.Y});
      for(int dir = 0; dir < 4; dir ++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(vis[nx][ny] || p[nx][ny] == -1) continue;
        vis[nx][ny] = vis[cur.X][cur.Y] + 1;
        q.push({nx, ny});
      }
    }
    if(pq.empty()) {
      cout << -1;
      return;
    }
    auto [val, xx, yy] = pq.top();
    pq.pop();
    cur_x = xx;
    cur_y = yy;
    f -= val;
    q = queue<pi>();
    for(int i = 0; i < n; i ++) fill(all(vis[i]), 0);
    q.push({cur_x, cur_y});
    vis[cur_x][cur_y] = 1;
    bool flag = false;
    while(sz(q)) {
      auto cur = q.front();
      q.pop();
      if(d[p[xx][yy]].X == cur.X && d[p[xx][yy]].Y == cur.Y) {
        cur_x = cur.X;
        cur_y = cur.Y;
        val = vis[cur.X][cur.Y]-1;
        flag = true;
        break;
      }
      for(int dir = 0; dir < 4; dir ++) {
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(vis[nx][ny] || p[nx][ny] == -1) continue;
        vis[nx][ny] = vis[cur.X][cur.Y] + 1;
        q.push({nx, ny});               
      }
    }
    f -= val;
    if(!flag || f < 0) {
      cout << -1;
      return;
    }
    f += 2*val;
    p[xx][yy] = 0;

  }
  cout << f;
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