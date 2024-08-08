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
typedef vector<int> vi;
typedef vector<ll> vl;

const char nl = '\n';
const int MX = 0x3f3f3f3f;
const int MOD = 1'000'000'007;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string board[55];
int vis[55][55][70];
void solve() {
  int n, m;
  cin >> n >> m;
  int sx, sy;
  for(int i = 0; i < n; i ++) {
    cin >> board[i];
    for(int j = 0; j < m; j ++) {
      if(board[i][j] == '0') tie(sx, sy) = {i, j};
    }
  }
  queue<ti> q;
  q.push({sx, sy, 0});
  vis[sx][sy][0] = 1;
  while(sz(q)) {
    auto [x, y, bit] = q.front();
    q.pop();
    for(int dir = 0; dir < 4; dir ++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      int nbit = bit;
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

      if(vis[nx][ny][nbit] || board[nx][ny] =='#') continue;
      if(board[nx][ny] >= 'A' && board[nx][ny] <= 'F') {
        if(!(1 & (nbit>>(board[nx][ny]-'A')))) continue;
      }
      else if(board[nx][ny] >= 'a' && board[nx][ny] <= 'f') {
        nbit = nbit | (1<<(board[nx][ny]-1));
      }
      q.push({nx, ny, nbit});
      vis[nx][ny][nbit] = vis[x][y][bit] + 1;
    }
  }
  int ans = MX;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) { 
      if(board[i][j] == '1') {
        for(int bit = 0; bit < 64; bit ++) {
          if(!vis[i][j][bit]) continue;
          ans = min(ans, vis[i][j][bit]);
        }
      }
    } 
  }
  cout << (ans==MX ? -1 : ans-1);
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