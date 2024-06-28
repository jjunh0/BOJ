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
char board[55][55];
int vis[55][55][(1<<6)];
void solve() {
  int n, m;
  cin >> m >> n;
  queue<tuple<int, int, int>> q;
  int cnt_x = 0, e_x, e_y;
  map<pi, int> mp;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) {
      cin >> board[i][j];
      if(board[i][j] == 'S') {
        q.push({i, j, 0});
        vis[i][j][0] = 1;
      }
      if(board[i][j] == 'X') {
        mp[{i, j}] = cnt_x++;
      }
      if(board[i][j] == 'E') tie(e_x, e_y) = {i, j};
    }
  }
  while(!q.empty()) {
    auto [x, y, bit] = q.front();
    q.pop();
    if(board[x][y] == 'E' && bit == (1<<cnt_x) - 1) {
      cout << vis[x][y][bit] - 1;
      return;
    }
    for(int dir = 0; dir < 4; dir ++) {
      int nx = dx[dir] + x;
      int ny = dy[dir] + y;
      int nbit = bit;
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(board[nx][ny] == '#') continue;
      if(board[nx][ny] == 'X') {
        nbit = (nbit | (1<<mp[{nx, ny}]));
      }
      if(vis[nx][ny][nbit]) continue;
      vis[nx][ny][nbit] = vis[x][y][bit] + 1;
      q.push({nx, ny, nbit});
    }
  }
  cout << cnt_x << nl;
  cout << vis[e_x][e_y][(1<<cnt_x) - 1] - 1;
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