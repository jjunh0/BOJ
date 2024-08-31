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
int ans[1005][1005];
void solve() {
  int n, m;
  cin >> n >> m;
  int board[n][m];
  int x, y;
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) {
      cin >> board[i][j];
      if(board[i][j] == 2) x = i, y = j;
    }
  }  
  
  queue<pi> q;
  q.push({x, y});
  ans[x][y] = 1;
  while(!q.empty()) {
    auto cur = q.front();
    q.pop();
    for(int dir = 0; dir < 4; dir ++) {
      int nx = cur.X + dx[dir];
      int ny = cur.Y + dy[dir];
      if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if(ans[nx][ny] > 0 || board[nx][ny] == 0) continue;
      ans[nx][ny] = ans[cur.X][cur.Y] + 1;
      q.push({nx, ny});
    }
  }
  for(int i = 0; i < n; i ++) {
    for(int j = 0; j < m; j ++) {
      if(board[i][j]) cout << (ans[i][j] != 0 ? ans[i][j] - 1 : -1) << ' ';
      else cout << 0 << ' '; 
    }
    cout << nl;
  }
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